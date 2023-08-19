.equ LOCALID_JENNY,  2

KailoTown_MapScripts::
	.byte 0

KailoTown_EventScript_Jenny::
  lock
  faceplayer
  textcolor NPC_TEXT_COLOR_FEMALE
  msgbox KailoTown_Text_JennyStopNoPassing
  closemessage
  release
  end

KailoTown_EventScript_Exit::
  call_if_lt VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, KailoTown_EventScript_JennyStop
  end

KailoTown_EventScript_JennyStop::
  lock
  textcolor NPC_TEXT_COLOR_FEMALE
  msgbox KailoTown_Text_JennyStopWait
  waitmessage
  delay 55
  closemessage
  addobject LOCALID_JENNY
  playse SE_PIN
  applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
  applymovement OBJ_EVENT_ID_PLAYER, KailoTown_Movement_JennyStopPlayerSuprised
  applymovement LOCALID_JENNY, KailoTown_Movement_JennyStopJennyWalkIn
  waitmovement 0
  msgbox KailoTown_Text_JennyStopUnsafe
  closemessage
  applymovement LOCALID_JENNY, KailoTown_Movement_JennyStop_JennyBack
  applymovement OBJ_EVENT_ID_PLAYER, KailoTown_Movement_JennyStopPlayerBack
  waitmovement 0
  applymovement LOCALID_JENNY, KailoTown_Movement_JennyStop_JennyBlock
  msgbox KailoTown_Text_JennyStopNoPassing
  closemessage
  release
  return

KailoTown_Movement_JennyStopPlayerSuprised::
  face_left
  step_end

KailoTown_Movement_JennyStopJennyWalkIn::
  walk_right
  walk_down
  walk_right
  walk_right
  walk_up
  walk_up
  walk_up
  walk_right
  walk_right
  walk_right
  walk_right
  walk_right
  step_end

KailoTown_Movement_JennyStopPlayerBack::
  walk_left
  walk_left
  walk_down
  face_up
  step_end

KailoTown_Movement_JennyStop_JennyBack::
  walk_left
  walk_left
  face_right
  step_end

KailoTown_Movement_JennyStop_JennyBlock::
  walk_right
  walk_right
  face_left
  step_end
