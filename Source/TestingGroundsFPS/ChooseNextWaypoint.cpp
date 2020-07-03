// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextWaypoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "TP_ThirdPerson/PatrolRoute.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
     // Get the patrol points
     auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
     auto PatrollingActor = Cast<ATP_ThirdPersonCharacter>(ControlledPawn);
     auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
     if (!ensure(PatrolRoute)) { return EBTNodeResult::Failed; }
     auto PatrolPoints = PatrolRoute->GetPatrolPoints();
     if(PatrolPoints.Num() == 0)
     {
          UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"));
          return EBTNodeResult::Failed;
     }

     //Set next patrol point
     auto BlackboardComp = OwnerComp.GetBlackboardComponent();
     auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
     BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);

     // Cycle the index
     auto NextIndex = (Index + 1) % PatrolPoints.Num();
     BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);


     return EBTNodeResult::Succeeded;
}