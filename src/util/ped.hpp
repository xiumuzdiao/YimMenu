#pragma once
#include "entity.hpp"
#include "gta/enums.hpp"
#include "math.hpp"
#include "natives.hpp"
#include "outfit.hpp"
#include "pointers.hpp"
#include "services/players/player_service.hpp"
#include "script.hpp"

namespace big::ped
{
	inline const std::map<int, const char*> task_names{
	    {0, "CTaskHandsUp"},
	    {1, "CTaskClimbLadder"},
	    {2, "CTaskExitVehicle"},
	    {3, "CTaskCombatRoll"},
	    {4, "CTaskAimGunOnFoot"},
	    {5, "CTaskMovePlayer"},
	    {6, "CTaskPlayerOnFoot"},
	    {8, "CTaskWeapon"},
	    {9, "CTaskPlayerWeapon"},
	    {10, "CTaskPlayerIdles"},
	    {12, "CTaskAimGun"},
	    {12, "CTaskComplex"},
	    {12, "CTaskFSMClone"},
	    {12, "CTaskMotionBase"},
	    {12, "CTaskMove"},
	    {12, "CTaskMoveBase"},
	    {12, "CTaskNMBehaviour"},
	    {12, "CTaskNavBase"},
	    {12, "CTaskScenario"},
	    {12, "CTaskSearchBase"},
	    {12, "CTaskSearchInVehicleBase"},
	    {12, "CTaskShockingEvent"},
	    {12, "CTaskTrainBase"},
	    {12, "CTaskVehicleFSM"},
	    {12, "CTaskVehicleGoTo"},
	    {12, "CTaskVehicleMissionBase"},
	    {12, "CTaskVehicleTempAction"},
	    {14, "CTaskPause"},
	    {15, "CTaskDoNothing"},
	    {16, "CTaskGetUp"},
	    {17, "CTaskGetUpAndStandStill"},
	    {18, "CTaskFallOver"},
	    {19, "CTaskFallAndGetUp"},
	    {20, "CTaskCrawl"},
	    {25, "CTaskComplexOnFire"},
	    {26, "CTaskDamageElectric"},
	    {28, "CTaskTriggerLookAt"},
	    {29, "CTaskClearLookAt"},
	    {30, "CTaskSetCharDecisionMaker"},
	    {31, "CTaskSetPedDefensiveArea"},
	    {32, "CTaskUseSequence"},
	    {34, "CTaskMoveStandStill"},
	    {35, "CTaskComplexControlMovement"},
	    {36, "CTaskMoveSequence"},
	    {38, "CTaskAmbientClips"},
	    {39, "CTaskMoveInAir"},
	    {40, "CTaskNetworkClone"},
	    {41, "CTaskUseClimbOnRoute"},
	    {42, "CTaskUseDropDownOnRoute"},
	    {43, "CTaskUseLadderOnRoute"},
	    {44, "CTaskSetBlockingOfNonTemporaryEvents"},
	    {45, "CTaskForceMotionState"},
	    {46, "CTaskSlopeScramble"},
	    {47, "CTaskGoToAndClimbLadder"},
	    {48, "CTaskClimbLadderFully"},
	    {49, "CTaskRappel"},
	    {50, "CTaskVault"},
	    {51, "CTaskDropDown"},
	    {52, "CTaskAffectSecondaryBehaviour"},
	    {53, "CTaskAmbientLookAtEvent"},
	    {54, "CTaskOpenDoor"},
	    {55, "CTaskShovePed"},
	    {56, "CTaskSwapWeapon"},
	    {57, "CTaskGeneralSweep"},
	    {58, "CTaskPolice"},
	    {59, "CTaskPoliceOrderResponse"},
	    {60, "CTaskPursueCriminal"},
	    {62, "CTaskArrestPed"},
	    {63, "CTaskArrestPed2"},
	    {64, "CTaskBusted"},
	    {65, "CTaskFirePatrol"},
	    {66, "CTaskHeliOrderResponse"},
	    {67, "CTaskHeliPassengerRappel"},
	    {68, "CTaskAmbulancePatrol"},
	    {69, "CTaskPoliceWantedResponse"},
	    {70, "CTaskSwat"},
	    {72, "CTaskSwatWantedResponse"},
	    {73, "CTaskSwatOrderResponse"},
	    {74, "CTaskSwatGoToStagingArea"},
	    {75, "CTaskSwatFollowInLine"},
	    {76, "CTaskWitness"},
	    {77, "CTaskGangPatrol"},
	    {78, "CTaskArmy"},
	    {80, "CTaskShockingEventWatch"},
	    {82, "CTaskShockingEventGoto"},
	    {83, "CTaskShockingEventHurryAway"},
	    {84, "CTaskShockingEventReactToAircraft"},
	    {85, "CTaskShockingEventReact"},
	    {86, "CTaskShockingEventBackAway"},
	    {87, "CTaskShockingPoliceInvestigate"},
	    {88, "CTaskShockingEventStopAndStare"},
	    {89, "CTaskShockingNiceCarPicture"},
	    {90, "CTaskShockingEventThreatResponse"},
	    {92, "CTaskTakeOffHelmet"},
	    {93, "CTaskCarReactToVehicleCollision"},
	    {95, "CTaskCarReactToVehicleCollisionGetOut"},
	    {97, "CTaskDyingDead"},
	    {100, "CTaskWanderingScenario"},
	    {101, "CTaskWanderingInRadiusScenario"},
	    {103, "CTaskMoveBetweenPointsScenario"},
	    {104, "CTaskChatScenario"},
	    {106, "CTaskCowerScenario"},
	    {107, "CTaskDeadBodyScenario"},
	    {114, "CTaskSayAudio"},
	    {116, "CTaskWaitForSteppingOut"},
	    {117, "CTaskCoupleScenario"},
	    {118, "CTaskUseScenario"},
	    {119, "CTaskUseVehicleScenario"},
	    {120, "CTaskUnalerted"},
	    {121, "CTaskStealVehicle"},
	    {122, "CTaskReactToPursuit"},
	    {125, "CTaskHitWall"},
	    {126, "CTaskCower"},
	    {127, "CTaskCrouch"},
	    {128, "CTaskMelee"},
	    {129, "CTaskMoveMeleeMovement"},
	    {130, "CTaskMeleeActionResult"},
	    {131, "CTaskMeleeUpperbodyAnims"},
	    {133, "CTaskMoVEScripted"},
	    {134, "CTaskScriptedAnimation"},
	    {135, "CTaskSynchronizedScene"},
	    {137, "CTaskComplexEvasiveStep"},
	    {138, "CTaskWalkRoundCarWhileWandering"},
	    {140, "CTaskComplexStuckInAir"},
	    {141, "CTaskWalkRoundEntity"},
	    {142, "CTaskMoveWalkRoundVehicle"},
	    {144, "CTaskReactToGunAimedAt"},
	    {146, "CTaskDuckAndCover"},
	    {147, "CTaskAggressiveRubberneck"},
	    {150, "CTaskInVehicleBasic"},
	    {151, "CTaskCarDriveWander"},
	    {152, "CTaskLeaveAnyCar"},
	    {153, "CTaskComplexGetOffBoat"},
	    {155, "CTaskCarSetTempAction"},
	    {156, "CTaskBringVehicleToHalt"},
	    {157, "CTaskCarDrive"},
	    {159, "CTaskPlayerDrive"},
	    {160, "CTaskEnterVehicle"},
	    {161, "CTaskEnterVehicleAlign"},
	    {162, "CTaskOpenVehicleDoorFromOutside"},
	    {163, "CTaskEnterVehicleSeat"},
	    {164, "CTaskCloseVehicleDoorFromInside"},
	    {165, "CTaskInVehicleSeatShuffle"},
	    {167, "CTaskExitVehicleSeat"},
	    {168, "CTaskCloseVehicleDoorFromOutside"},
	    {169, "CTaskControlVehicle"},
	    {170, "CTaskMotionInAutomobile"},
	    {171, "CTaskMotionOnBicycle"},
	    {172, "CTaskMotionOnBicycleController"},
	    {173, "CTaskMotionInVehicle"},
	    {174, "CTaskMotionInTurret"},
	    {175, "CTaskReactToBeingJacked"},
	    {176, "CTaskReactToBeingAskedToLeaveVehicle"},
	    {177, "CTaskTryToGrabVehicleDoor"},
	    {178, "CTaskGetOnTrain"},
	    {179, "CTaskGetOffTrain"},
	    {180, "CTaskRideTrain"},
	    {190, "CTaskMountThrowProjectile"},
	    {195, "CTaskGoToCarDoorAndStandStill"},
	    {196, "CTaskMoveGoToVehicleDoor"},
	    {197, "CTaskSetPedInVehicle"},
	    {198, "CTaskSetPedOutOfVehicle"},
	    {199, "CTaskVehicleMountedWeapon"},
	    {200, "CTaskVehicleGun"},
	    {201, "CTaskVehicleProjectile"},
	    {204, "CTaskSmashCarWindow"},
	    {205, "CTaskMoveGoToPoint"},
	    {206, "CTaskMoveAchieveHeading"},
	    {207, "CTaskMoveFaceTarget"},
	    {208, "CTaskComplexGoToPointAndStandStillTimed"},
	    {208, "CTaskMoveGoToPointAndStandStill"},
	    {209, "CTaskMoveFollowPointRoute"},
	    {210, "CTaskMoveSeekEntity_CEntitySeekPosCalculatorStandard"},
	    {211, "CTaskMoveSeekEntity_CEntitySeekPosCalculatorLastNavMeshIntersection"},
	    {212, "CTaskMoveSeekEntity_CEntitySeekPosCalculatorLastNavMeshIntersection2"},
	    {213, "CTaskMoveSeekEntity_CEntitySeekPosCalculatorXYOffsetFixed"},
	    {214, "CTaskMoveSeekEntity_CEntitySeekPosCalculatorXYOffsetFixed2"},
	    {215, "CTaskExhaustedFlee"},
	    {216, "CTaskGrowlAndFlee"},
	    {217, "CTaskScenarioFlee"},
	    {218, "CTaskSmartFlee"},
	    {219, "CTaskFlyAway"},
	    {220, "CTaskWalkAway"},
	    {221, "CTaskWander"},
	    {222, "CTaskWanderInArea"},
	    {223, "CTaskFollowLeaderInFormation"},
	    {224, "CTaskGoToPointAnyMeans"},
	    {225, "CTaskTurnToFaceEntityOrCoord"},
	    {226, "CTaskFollowLeaderAnyMeans"},
	    {228, "CTaskFlyToPoint"},
	    {229, "CTaskFlyingWander"},
	    {230, "CTaskGoToPointAiming"},
	    {231, "CTaskGoToScenario"},
	    {233, "CTaskSeekEntityAiming"},
	    {234, "CTaskSlideToCoord"},
	    {235, "CTaskSwimmingWander"},
	    {237, "CTaskMoveTrackingEntity"},
	    {238, "CTaskMoveFollowNavMesh"},
	    {239, "CTaskMoveGoToPointOnRoute"},
	    {240, "CTaskEscapeBlast"},
	    {241, "CTaskMoveWander"},
	    {242, "CTaskMoveBeInFormation"},
	    {243, "CTaskMoveCrowdAroundLocation"},
	    {244, "CTaskMoveCrossRoadAtTrafficLights"},
	    {245, "CTaskMoveWaitForTraffic"},
	    {246, "CTaskMoveGoToPointStandStillAchieveHeading"},
	    {251, "CTaskMoveGetOntoMainNavMesh"},
	    {252, "CTaskMoveSlideToCoord"},
	    {253, "CTaskMoveGoToPointRelativeToEntityAndStandStill"},
	    {254, "CTaskHelicopterStrafe"},
	    {256, "CTaskGetOutOfWater"},
	    {259, "CTaskMoveFollowEntityOffset"},
	    {261, "CTaskFollowWaypointRecording"},
	    {264, "CTaskMotionPed"},
	    {265, "CTaskMotionPedLowLod"},
	    {268, "CTaskHumanLocomotion"},
	    {269, "CTaskMotionBasicLocomotionLowLod"},
	    {270, "CTaskMotionStrafing"},
	    {271, "CTaskMotionTennis"},
	    {272, "CTaskMotionAiming"},
	    {273, "CTaskBirdLocomotion"},
	    {274, "CTaskFlightlessBirdLocomotion"},
	    {278, "CTaskFishLocomotion"},
	    {279, "CTaskQuadLocomotion"},
	    {280, "CTaskMotionDiving"},
	    {281, "CTaskMotionSwimming"},
	    {282, "CTaskMotionParachuting"},
	    {283, "CTaskMotionDrunk"},
	    {284, "CTaskRepositionMove"},
	    {285, "CTaskMotionAimingTransition"},
	    {286, "CTaskThrowProjectile"},
	    {287, "CTaskCover"},
	    {288, "CTaskMotionInCover"},
	    {289, "CTaskAimAndThrowProjectile"},
	    {290, "CTaskGun"},
	    {291, "CTaskAimFromGround"},
	    {295, "CTaskAimGunVehicleDriveBy"},
	    {296, "CTaskAimGunScripted"},
	    {298, "CTaskReloadGun"},
	    {299, "CTaskWeaponBlocked"},
	    {300, "CTaskEnterCover"},
	    {301, "CTaskExitCover"},
	    {302, "CTaskAimGunFromCoverIntro"},
	    {303, "CTaskAimGunFromCoverOutro"},
	    {304, "CTaskAimGunBlindFire"},
	    {307, "CTaskCombatClosestTargetInArea"},
	    {308, "CTaskCombatAdditionalTask"},
	    {309, "CTaskInCover"},
	    {313, "CTaskAimSweep"},
	    {318, "CTaskSharkCircle"},
	    {319, "CTaskSharkAttack"},
	    {320, "CTaskAgitated"},
	    {321, "CTaskAgitatedAction"},
	    {322, "CTaskConfront"},
	    {323, "CTaskIntimidate"},
	    {324, "CTaskShove"},
	    {325, "CTaskShoved"},
	    {327, "CTaskCrouchToggle"},
	    {328, "CTaskRevive"},
	    {334, "CTaskParachute"},
	    {335, "CTaskParachuteObject"},
	    {336, "CTaskTakeOffPedVariation"},
	    {339, "CTaskCombatSeekCover"},
	    {341, "CTaskCombatFlank"},
	    {342, "CTaskCombat"},
	    {343, "CTaskCombatMounted"},
	    {344, "CTaskMoveCircle"},
	    {345, "CTaskMoveCombatMounted"},
	    {346, "CTaskSearch"},
	    {347, "CTaskSearchOnFoot"},
	    {348, "CTaskSearchInAutomobile"},
	    {349, "CTaskSearchInBoat"},
	    {350, "CTaskSearchInHeli"},
	    {351, "CTaskThreatResponse"},
	    {352, "CTaskInvestigate"},
	    {353, "CTaskStandGuardFSM"},
	    {354, "CTaskPatrol"},
	    {355, "CTaskShootAtTarget"},
	    {356, "CTaskSetAndGuardArea"},
	    {357, "CTaskStandGuard"},
	    {358, "CTaskSeparate"},
	    {359, "CTaskStayInCover"},
	    {360, "CTaskVehicleCombat"},
	    {361, "CTaskVehiclePersuit"},
	    {362, "CTaskVehicleChase"},
	    {363, "CTaskDraggingToSafety"},
	    {364, "CTaskDraggedToSafety"},
	    {365, "CTaskVariedAimPose"},
	    {366, "CTaskMoveWithinAttackWindow"},
	    {367, "CTaskMoveWithinDefensiveArea"},
	    {368, "CTaskShootOutTire"},
	    {369, "CTaskShellShocked"},
	    {370, "CTaskBoatChase"},
	    {371, "CTaskBoatCombat"},
	    {372, "CTaskBoatStrafe"},
	    {373, "CTaskHeliChase"},
	    {374, "CTaskHeliCombat"},
	    {375, "CTaskSubmarineCombat"},
	    {376, "CTaskSubmarineChase"},
	    {377, "CTaskPlaneChase"},
	    {378, "CTaskTargetUnreachable"},
	    {379, "CTaskTargetUnreachableInInterior"},
	    {380, "CTaskTargetUnreachableInExterior"},
	    {381, "CTaskStealthKill"},
	    {382, "CTaskWrithe"},
	    {383, "CTaskAdvance"},
	    {384, "CTaskCharge"},
	    {385, "CTaskMoveToTacticalPoint"},
	    {386, "CTaskToHurtTransit"},
	    {387, "CTaskAnimatedHitByExplosion"},
	    {388, "CTaskNMRelax"},
	    {390, "CTaskNMPose"},
	    {391, "CTaskNMBrace"},
	    {392, "CTaskNMBuoyancy"},
	    {393, "CTaskNMInjuredOnGround"},
	    {394, "CTaskNMShot"},
	    {395, "CTaskNMHighFall"},
	    {396, "CTaskNMBalance"},
	    {397, "CTaskNMElectrocute"},
	    {398, "CTaskNMPrototype"},
	    {399, "CTaskNMExplosion"},
	    {400, "CTaskNMOnFire"},
	    {401, "CTaskNMScriptControl"},
	    {402, "CTaskNMJumpRollFromRoadVehicle"},
	    {403, "CTaskNMFlinch"},
	    {404, "CTaskNMSit"},
	    {405, "CTaskNMFallDown"},
	    {406, "CTaskBlendFromNM"},
	    {407, "CTaskNMControl"},
	    {408, "CTaskNMDangle"},
	    {411, "CTaskNMGenericAttach"},
	    {412, "CTaskNMDrunk"},
	    {413, "CTaskNMDraggingToSafety"},
	    {414, "CTaskNMThroughWindscreen"},
	    {415, "CTaskNMRiverRapids"},
	    {416, "CTaskNMSimple"},
	    {417, "CTaskRageRagdoll"},
	    {420, "CTaskJumpVault"},
	    {421, "CTaskJump"},
	    {422, "CTaskFall"},
	    {424, "CTaskReactAimWeapon"},
	    {425, "CTaskChat"},
	    {426, "CTaskMobilePhone"},
	    {427, "CTaskReactToDeadPed"},
	    {429, "CTaskSearchForUnknownThreat"},
	    {431, "CTaskBomb"},
	    {432, "CTaskDetonator"},
	    {434, "CTaskAnimatedAttach"},
	    {440, "CTaskCutScene"},
	    {441, "CTaskReactToExplosion"},
	    {442, "CTaskReactToImminentExplosion"},
	    {443, "CTaskDiveToGround"},
	    {444, "CTaskReactAndFlee"},
	    {445, "CTaskSidestep"},
	    {446, "CTaskCallPolice"},
	    {447, "CTaskReactInDirection"},
	    {448, "CTaskReactToBuddyShot"},
	    {453, "CTaskVehicleGoToAutomobileNew"},
	    {454, "CTaskVehicleGoToPlane"},
	    {455, "CTaskVehicleGoToHelicopter"},
	    {456, "CTaskVehicleGoToSubmarine"},
	    {457, "CTaskVehicleGoToBoat"},
	    {458, "CTaskVehicleGoToPointAutomobile"},
	    {459, "CTaskVehicleGoToPointWithAvoidanceAutomobile"},
	    {460, "CTaskVehiclePursue"},
	    {461, "CTaskVehicleRam"},
	    {462, "CTaskVehicleSpinOut"},
	    {463, "CTaskVehicleApproach"},
	    {464, "CTaskVehicleThreePointTurn"},
	    {465, "CTaskVehicleDeadDriver"},
	    {466, "CTaskVehicleCruiseNew"},
	    {467, "CTaskVehicleCruiseBoat"},
	    {468, "CTaskVehicleStop"},
	    {469, "CTaskVehiclePullOver"},
	    {470, "CTaskVehiclePassengerExit"},
	    {471, "CTaskVehicleFlee"},
	    {472, "CTaskVehicleFleeAirborne"},
	    {473, "CTaskVehicleFleeBoat"},
	    {474, "CTaskVehicleFollowRecording"},
	    {475, "CTaskVehicleFollow"},
	    {476, "CTaskVehicleBlock"},
	    {477, "CTaskVehicleBlockCruiseInFront"},
	    {478, "CTaskVehicleBlockBrakeInFront"},
	    {479, "CTaskVehicleBlockBackAndForth"},
	    {480, "CTaskVehicleCrash"},
	    {481, "CTaskVehicleLand"},
	    {482, "CTaskVehicleLandPlane"},
	    {483, "CTaskVehicleHover"},
	    {484, "CTaskVehicleAttack"},
	    {485, "CTaskVehicleAttackTank"},
	    {486, "CTaskVehicleCircle"},
	    {487, "CTaskVehiclePoliceBehaviour"},
	    {488, "CTaskVehiclePoliceBehaviourHelicopter"},
	    {489, "CTaskVehiclePoliceBehaviourBoat"},
	    {490, "CTaskVehicleEscort"},
	    {491, "CTaskVehicleHeliProtect"},
	    {493, "CTaskVehiclePlayerDriveAutomobile"},
	    {494, "CTaskVehiclePlayerDriveBike"},
	    {495, "CTaskVehiclePlayerDriveBoat"},
	    {496, "CTaskVehiclePlayerDriveSubmarine"},
	    {497, "CTaskVehiclePlayerDriveSubmarineCar"},
	    {498, "CTaskVehiclePlayerDrivePlane"},
	    {499, "CTaskVehiclePlayerDriveHeli"},
	    {500, "CTaskVehiclePlayerDriveAutogyro"},
	    {501, "CTaskVehiclePlayerDriveDiggerArm"},
	    {502, "CTaskVehiclePlayerDriveTrain"},
	    {503, "CTaskVehiclePlaneChase"},
	    {504, "CTaskVehicleNoDriver"},
	    {505, "CTaskVehicleAnimation"},
	    {506, "CTaskVehicleConvertibleRoof"},
	    {507, "CTaskVehicleParkNew"},
	    {508, "CTaskVehicleFollowWaypointRecording"},
	    {509, "CTaskVehicleGoToNavmesh"},
	    {510, "CTaskVehicleReactToCopSiren"},
	    {511, "CTaskVehicleGotoLongRange"},
	    {512, "CTaskVehicleWait"},
	    {513, "CTaskVehicleReverse"},
	    {514, "CTaskVehicleBrake"},
	    {515, "CTaskVehicleHandBrake"},
	    {516, "CTaskVehicleTurn"},
	    {517, "CTaskVehicleGoForward"},
	    {518, "CTaskVehicleSwerve"},
	    {519, "CTaskVehicleFlyDirection"},
	    {520, "CTaskVehicleHeadonCollision"},
	    {521, "CTaskVehicleBoostUseSteeringAngle"},
	    {522, "CTaskVehicleShotTire"},
	    {523, "CTaskVehicleBurnout"},
	    {524, "CTaskVehicleRevEngine"},
	    {525, "CTaskVehicleSurfaceInSubmarine"},
	    {526, "CTaskVehiclePullAlongside"},
	    {527, "CTaskVehicleTransformToSubmarine"},
	    {528, "CTaskAnimatedFallback"},
	};

	bool change_player_model(const Hash hash);
	bool steal_outfit(const Ped target);
	void clone_ped(const Ped src, const Ped target);
	void steal_identity(const Ped target);
	void kill_ped(const Ped ped);
	Ped spawn(ePedType pedType, Hash hash, Ped clone, Vector3 location, float heading, bool is_networked = true);
	void set_ped_random_component_variation(Ped ped);
	player_ptr get_player_from_ped(Ped ped);
	bool load_animation_dict(const char* dict);
	void ped_play_animation(Ped ped, const std::string_view& animDict, const std::string_view& animName, float speed = 4.f, float speedMultiplier = -4.f, int duration = -1, int flag = 0, float playbackRate = 0, bool lockPos = false, Vector3 pos = {}, Vector3 rot = {}, int ik_flags = 0);
	void ped_enter_vehicle_animated(Ped ped, Vehicle veh, eVehicleSeats seat, int movespeed);
	bool is_ped_a_friend(Ped ped, CPed* ped_ptr);
}
