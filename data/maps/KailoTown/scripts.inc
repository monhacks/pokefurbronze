.equ LOCALID_JENNY,  2
.equ LOCALID_DAMIEN,  1
.equ LOCALID_VICTOR,  4
.equ LOCALID_JOY,  5
.equ LOCALID_GIRL,  3

@ one tile run is 0.125 sec
@ one tile walk is 0.25 sec

KailoTown_MapScripts::
  map_script MAP_SCRIPT_ON_FRAME_TABLE, KailoTown_OnFrame
  map_script MAP_SCRIPT_ON_TRANSITION, KailoTown_OnTransition
  map_script MAP_SCRIPT_ON_LOAD, KailoTown_OnLoad
	.byte 0

KailoTown_OnTransition::
  call_if_unset FLAG_0x205, KailoTown_EventScript_FlagSetup
  end

KailoTown_OnLoad::
  call_if_unset FLAG_0x200, KailoTown_EventScript_IntroSetup
  call_if_lt VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 4, KailoTown_EventScript_AfterRain
  end

KailoTown_OnFrame::
  map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 0, KailoTown_EventScript_IntroScript
  .2byte 0

KailoTown_EventScript_IntroSetup::
  call KailoTown_EventScript_PuddleDebuggersCave
  call KailoTown_EventScript_PuddleLab
  call KailoTown_EventScript_PuddleGym
  call KailoTown_EventScript_PuddleHause
  call KailoTown_EventScript_PuddlePokemonCenter
  setflag FLAG_0x201
  setweather WEATHER_DOWNPOUR
  setobjectmovementtype OBJ_EVENT_ID_PLAYER, MOVEMENT_TYPE_INVISIBLE
  return

KailoTown_EventScript_AfterRain::
  call KailoTown_EventScript_PuddleDebuggersCave
  call KailoTown_EventScript_PuddleHause
  call KailoTown_EventScript_PuddlePokemonCenter
  return

KailoTown_EventScript_PuddleDebuggersCave::
  setmetatile 14, 8, 0x1AA, 0
  setmetatile 14, 9, 0x1B2, 0
  setmetatile 12, 9, 0x1A8, 0
  setmetatile 12, 8, 0x1A8, 0
  setmetatile 13, 9, 0x1A9, 0
  setmetatile 13, 8, 0x1A9, 0
  return
  
KailoTown_EventScript_PuddleGym::
  setmetatile 5, 6, 0x1A1, 0
  setmetatile 5, 8, 0x1B1, 0
  setmetatile 5, 7, 0x1A9, 0
  return

KailoTown_EventScript_PuddleLab::
  setmetatile 8, 14, 0x1A2, 0
  setmetatile 8, 15, 0x1AA, 0
  setmetatile 8, 16, 0x1AA, 0
  setmetatile 8, 17, 0x1B2, 0
  setmetatile 5, 16, 0x1B1, 0
  setmetatile 6, 16, 0x1B1, 0
  setmetatile 4, 16, 0x1B0, 0
  setmetatile 7, 17, 0x1B0, 0
  setmetatile 4, 15, 0x1A8, 0
  setmetatile 4, 14, 0x1A0, 0
  setmetatile 6, 14, 0x1A9, 0
  setmetatile 7, 14, 0x1A9, 0
  setmetatile 5, 15, 0x1A9, 0
  setmetatile 6, 15, 0x1A9, 0
  setmetatile 7, 15, 0x1A9, 0
  setmetatile 7, 16, 0x1A9, 0
  return

KailoTown_EventScript_PuddleHause::
  setmetatile 18, 11, 0x1AA, 0
  setmetatile 18, 12, 0x1AA, 0
  setmetatile 18, 13, 0x1AA, 0
  setmetatile 18, 14, 0x1B2, 0
  setmetatile 17, 14, 0x1B1, 0
  setmetatile 16, 14, 0x1B1, 0
  setmetatile 16, 12, 0x1A8, 0
  setmetatile 16, 13, 0x1A8, 0
  setmetatile 16, 11, 0x1A0, 0
  setmetatile 17, 11, 0x1A9, 0
  setmetatile 17, 12, 0x1A9, 0
  setmetatile 17, 13, 0x1A9, 0
  return

KailoTown_EventScript_PuddlePokemonCenter::
  setmetatile 16, 18, 0x1A1, 0
  setmetatile 17, 18, 0x1A1, 0
  setmetatile 18, 18, 0x1A1, 0
  setmetatile 19, 18, 0x1AA, 0
  setmetatile 19, 19, 0x1AA, 0
  setmetatile 19, 20, 0x1AA, 0
  setmetatile 19, 21, 0x1B2, 0
  setmetatile 18, 22, 0x1B2, 0
  setmetatile 17, 22, 0x1B0, 0
  setmetatile 16, 21, 0x1B0, 0
  setmetatile 15, 20, 0x1B0, 0
  setmetatile 15, 19, 0x1A8, 0
  setmetatile 15, 18, 0x1A8, 0
  setmetatile 16, 19, 0x1A9, 0
  setmetatile 17, 19, 0x1A9, 0
  setmetatile 18, 19, 0x1A9, 0
  setmetatile 16, 20, 0x1A9, 0
  setmetatile 17, 20, 0x1A9, 0
  setmetatile 18, 20, 0x1A9, 0
  setmetatile 17, 21, 0x1A9, 0
  setmetatile 18, 21, 0x1A9, 0
  return

KailoTown_EventScript_FlagSetup::
  setflag FLAG_0x205
  setflag FLAG_0x202
  return

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
  message KailoTown_Text_JennyStopWait
  waitmessage
  delay 85
  closemessage
  addobject LOCALID_JENNY
  playse SE_PIN
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
  emote_exclamation_mark
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

KailoTown_EventScript_IntroScript::
  lock
  doweather
  applymovement LOCALID_DAMIEN, KailoTown_Movement_Intro_DamienStart
  waitmovement 0
  opendoor 5, 4
  waitdooranim
  applymovement LOCALID_DAMIEN, KailoTown_Movement_Intro_DamienEnd
  delay 85
  delay 85
  delay 85
  playmoncry SPECIES_LUGIA, CRY_MODE_WEAK
  delay 50
  applymovement LOCALID_DAMIEN, KailoTown_Movement_JennyStopPlayerSuprised
  delay 85
  delay 85
  special SpawnCameraObject
  applymovement OBJ_EVENT_ID_CAMERA, KailoTown_Movement_Intro_ToLab
  waitmovement 0
  opendoor 4, 13
  waitdooranim
  addobject LOCALID_VICTOR
  applymovement LOCALID_VICTOR, KailoTown_Movement_Intro_VictorStart
  delay 37
  applymovement OBJ_EVENT_ID_CAMERA, KailoTown_Movement_Intro_CameraMiddle
  delay 50
  addobject LOCALID_JOY
  applymovement LOCALID_JOY, KailoTown_Movement_Intro_JoyStart
  waitmovement 0
  delay 85
  applymovement LOCALID_VICTOR, KailoTown_Movement_Intro_VictorEnd
  applymovement LOCALID_JOY, KailoTown_Movement_Intro_JoyEnd
  delay 37
  applymovement OBJ_EVENT_ID_CAMERA, KailoTown_Movement_Intro_End
  waitmovement 0
  delay 85
  warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
  special RemoveCameraObject
  waitstate
  setflag FLAG_0x200
  clearflag FLAG_0x201
  setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
  release
  return

KailoTown_Movement_Intro_DamienStart::
  walk_slow_down
  walk_slow_down
  walk_slow_up
  walk_slow_up
  walk_slow_down
  walk_in_place_faster_down
  walk_in_place_faster_left
  walk_in_place_faster_right
  walk_slow_up
  walk_in_place_faster_left
  walk_in_place_faster_right
  walk_in_place_faster_down
  walk_in_place_faster_up
  walk_in_place_faster_up
  step_end
  
KailoTown_Movement_Intro_DamienEnd::
  walk_slow_up
  walk_in_place_faster_down
  step_end

KailoTown_Movement_Intro_ToLab::
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  walk_slow_down
  step_end

KailoTown_Movement_Intro_VictorStart::
  walk_down
  walk_down
  walk_right
  walk_right
  walk_right
  walk_right
  walk_right
  walk_down
  walk_down
  walk_down
  walk_right
  walk_right
  step_end

KailoTown_Movement_Intro_CameraMiddle::
  walk_right
  walk_right
  walk_right
  walk_right
  walk_down
  walk_down
  walk_down
  walk_right
  walk_right
  step_end

KailoTown_Movement_Intro_JoyStart::
  walk_left
  walk_left
  walk_left
  walk_left
  walk_left
  step_end


KailoTown_Movement_Intro_VictorEnd::
  walk_left
  walk_left
  walk_up
  walk_up
  walk_up
  walk_left
  walk_left
  walk_left
  walk_left
  set_invisible
  step_end

KailoTown_Movement_Intro_JoyEnd::
  walk_left
  walk_left
  walk_left
  walk_up
  walk_up
  walk_up
  walk_left
  walk_left
  walk_left
  walk_left
  set_invisible
  step_end

KailoTown_Movement_Intro_End::
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_right
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  walk_slow_up
  step_end
