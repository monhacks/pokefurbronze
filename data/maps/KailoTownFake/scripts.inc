.equ LOCALID_DAMIEN,  1
.equ LOCALID_VICTOR,  3
.equ LOCALID_JOY,  2

KailoTownFake_MapScripts::
  map_script MAP_SCRIPT_ON_FRAME_TABLE, KailoTownFake_OnFrame
  map_script MAP_SCRIPT_ON_LOAD, KailoTownFake_OnLoad
	.byte 0

KailoTownFake_OnFrame::
  map_script_2 VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 0, KailoTownFake_EventScript_IfIntroScript
  .2byte 0

KailoTownFake_OnLoad::
  call_if_unset FLAG_IS_INTRO_COMPLETED, KailoTownFake_EventScript_IntroSetup
  end

KailoTownFake_EventScript_IfIntroScript::
  call_if_unset FLAG_IS_INTRO_COMPLETED, KailoTownFake_EventScript_IntroScript
  end

KailoTownFake_EventScript_IntroSetup::
  call KailoTownFake_EventScript_PuddleDebuggersCave
  call KailoTownFake_EventScript_PuddleLab
  call KailoTownFake_EventScript_PuddleGym
  call KailoTownFake_EventScript_PuddleHause
  call KailoTownFake_EventScript_PuddlePokemonCenter
  setflag FLAG_HIDE_CUTSCENE_DUMMIES
  setflag FLAG_HIDE_PLAYER
  return

KailoTownFake_EventScript_PuddleDebuggersCave::
  setmetatile 14, 8, 0x1AA, 0
  setmetatile 14, 9, 0x1B2, 0
  setmetatile 12, 9, 0x1A8, 0
  setmetatile 12, 8, 0x1A8, 0
  setmetatile 13, 9, 0x1A9, 0
  setmetatile 13, 8, 0x1A9, 0
  return
  
KailoTownFake_EventScript_PuddleGym::
  setmetatile 5, 6, 0x1A1, 0
  setmetatile 5, 8, 0x1B1, 0
  setmetatile 5, 7, 0x1A9, 0
  return

KailoTownFake_EventScript_PuddleLab::
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

KailoTownFake_EventScript_PuddleHause::
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

KailoTownFake_EventScript_PuddlePokemonCenter::
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

KailoTownFake_EventScript_IntroScript::
  lock
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienStart
  playse SE_THUNDER
  special SpawnCameraObject
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienLookRight
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienLookLeft
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienMiddle
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienLookRight
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienLookLeft
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienLookDown
  waitmovement 0
  delay 30
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienOpenDoor
  waitmovement 0
  delay 30
  opendoor 5, 4
  waitdooranim
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienEnd
  waitmovement 0
  delay 80
  delay 80
  delay 80
  delay 80
  delay 80
  fadescreen FADE_TO_WHITE
  fadescreen FADE_FROM_WHITE
  playse SE_THUNDER
  playmoncry SPECIES_LUGIA, CRY_MODE_FAINT
  delay 50
  playse SE_THUNDER2
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienSuprised
  playse SE_PIN
  delay 80
  delay 50
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_ToLab
  waitmovement 0
  opendoor 4, 13
  waitdooranim
  addobject LOCALID_VICTOR
  applymovement LOCALID_VICTOR, KailoTownFake_Movement_Intro_VictorStart
  delay 37
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_CameraMiddle
  delay 50
  addobject LOCALID_JOY
  applymovement LOCALID_JOY, KailoTownFake_Movement_Intro_JoyStart
  playse SE_THUNDER
  delay 40
  playse SE_THUNDER2
  waitmovement 0
  delay 85
  applymovement LOCALID_VICTOR, KailoTownFake_Movement_Intro_VictorEnd
  applymovement LOCALID_JOY, KailoTownFake_Movement_Intro_JoyEnd
  delay 37
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_End
  waitmovement 0
  delay 50
  setweather WEATHER_SUNNY
  doweather
  delay 30
  fadescreen FADE_TO_WHITE
  setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
  setflag FLAG_IS_INTRO_COMPLETED
  clearflag FLAG_HIDE_PLAYER
  delay 85
  warpsilent MAP_KAILO_TOWN_PLAYERS_HOUSE_2F, 1, 5
  waitstate
  release
  return

KailoTownFake_Movement_Intro_DamienLookRight::
  face_right
  step_end

KailoTownFake_Movement_Intro_DamienLookLeft::
  face_left
  step_end

KailoTownFake_Movement_Intro_DamienLookDown::
  face_down
  step_end

KailoTownFake_Movement_Intro_DamienStart::
  walk_slow_down
  walk_slow_down
  walk_slow_up
  walk_slow_up
  walk_slow_down
  step_end

KailoTownFake_Movement_Intro_DamienMiddle::
  walk_slow_up
  step_end

KailoTownFake_Movement_Intro_DamienOpenDoor::
  walk_in_place_up
  walk_in_place_up
  step_end
  
KailoTownFake_Movement_Intro_DamienEnd::
  walk_slow_up
  walk_in_place_faster_down
  step_end

KailoTownFake_Movement_Intro_DamienSuprised::
  emote_double_exclamation_mark
  face_left
  step_end

KailoTownFake_Movement_Intro_ToLab::
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

KailoTownFake_Movement_Intro_VictorStart::
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

KailoTownFake_Movement_Intro_CameraMiddle::
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

KailoTownFake_Movement_Intro_JoyStart::
  walk_left
  walk_left
  walk_left
  walk_left
  walk_left
  step_end


KailoTownFake_Movement_Intro_VictorEnd::
  walk_left
  walk_left
  walk_up
  walk_up
  walk_up
  walk_left
  walk_left
  walk_left
  walk_left
  step_end

KailoTownFake_Movement_Intro_JoyEnd::
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
  step_end

KailoTownFake_Movement_Intro_End::
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
