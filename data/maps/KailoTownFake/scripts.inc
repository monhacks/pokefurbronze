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
  return

KailoTownFake_EventScript_PuddleDebuggersCave::
  setmetatile 14, 20, 0x1AA, 0
  setmetatile 14, 21, 0x1B2, 0
  setmetatile 12, 21, 0x1A8, 0
  setmetatile 12, 20, 0x1A8, 0
  setmetatile 13, 21, 0x1A9, 0
  setmetatile 13, 20, 0x1A9, 0
  return
  
KailoTownFake_EventScript_PuddleGym::
  setmetatile 5, 18, 0x1A1, 0
  setmetatile 5, 20, 0x1B1, 0
  setmetatile 5, 19, 0x1A9, 0
  return

KailoTownFake_EventScript_PuddleLab::
  setmetatile 8, 26, 0x1A2, 0
  setmetatile 8, 27, 0x1AA, 0
  setmetatile 8, 28, 0x1AA, 0
  setmetatile 8, 29, 0x1B2, 0
  setmetatile 5, 28, 0x1B1, 0
  setmetatile 6, 28, 0x1B1, 0
  setmetatile 4, 28, 0x1B0, 0
  setmetatile 7, 29, 0x1B0, 0
  setmetatile 4, 27, 0x1A8, 0
  setmetatile 4, 26, 0x1A0, 0
  setmetatile 6, 26, 0x1A9, 0
  setmetatile 7, 26, 0x1A9, 0
  setmetatile 5, 27, 0x1A9, 0
  setmetatile 6, 27, 0x1A9, 0
  setmetatile 7, 27, 0x1A9, 0
  setmetatile 7, 28, 0x1A9, 0
  return

KailoTownFake_EventScript_PuddleHause::
  setmetatile 18, 23, 0x1AA, 0
  setmetatile 18, 24, 0x1AA, 0
  setmetatile 18, 25, 0x1AA, 0
  setmetatile 18, 26, 0x1B2, 0
  setmetatile 17, 26, 0x1B1, 0
  setmetatile 16, 26, 0x1B1, 0
  setmetatile 16, 24, 0x1A8, 0
  setmetatile 16, 25, 0x1A8, 0
  setmetatile 16, 23, 0x1A0, 0
  setmetatile 17, 23, 0x1A9, 0
  setmetatile 17, 24, 0x1A9, 0
  setmetatile 17, 25, 0x1A9, 0
  return

KailoTownFake_EventScript_PuddlePokemonCenter::
  setmetatile 16, 30, 0x1A1, 0
  setmetatile 17, 30, 0x1A1, 0
  setmetatile 18, 30, 0x1A1, 0
  setmetatile 19, 30, 0x1AA, 0
  setmetatile 19, 31, 0x1AA, 0
  setmetatile 19, 32, 0x1AA, 0
  setmetatile 19, 33, 0x1B2, 0
  setmetatile 18, 34, 0x1B2, 0
  setmetatile 17, 34, 0x1B0, 0
  setmetatile 16, 33, 0x1B0, 0
  setmetatile 15, 32, 0x1B0, 0
  setmetatile 15, 31, 0x1A8, 0
  setmetatile 15, 30, 0x1A8, 0
  setmetatile 16, 31, 0x1A9, 0
  setmetatile 17, 31, 0x1A9, 0
  setmetatile 18, 31, 0x1A9, 0
  setmetatile 16, 32, 0x1A9, 0
  setmetatile 17, 32, 0x1A9, 0
  setmetatile 18, 32, 0x1A9, 0
  setmetatile 17, 33, 0x1A9, 0
  setmetatile 18, 33, 0x1A9, 0
  return

KailoTownFake_EventScript_IntroScript::
  lock
  setweather WEATHER_RAIN_THUNDERSTORM
  doweather
  delay 20
  fadescreen FADE_TO_BLACK
  special SpawnCameraObject
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_CameraSetup
  waitmovement 0
  fadescreen FADE_FROM_BLACK
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienStart
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
  opendoor 5, 16
  waitdooranim
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienEnd
  waitmovement 0
  delay 85
  delay 85
  delay 85
  playse SE_THUNDER2
  playmoncry SPECIES_LUGIA, CRY_MODE_WEAK
  delay 20
  playse SE_THUNDER2
  applymovement LOCALID_DAMIEN, KailoTownFake_Movement_Intro_DamienSuprised
  playse SE_PIN
  delay 85
  delay 50
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_ToLab
  waitmovement 0
  opendoor 4, 25
  waitdooranim
  addobject LOCALID_VICTOR
  applymovement LOCALID_VICTOR, KailoTownFake_Movement_Intro_VictorStart
  delay 37
  applymovement OBJ_EVENT_ID_CAMERA, KailoTownFake_Movement_Intro_CameraMiddle
  delay 50
  addobject LOCALID_JOY
  applymovement LOCALID_JOY, KailoTownFake_Movement_Intro_JoyStart
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
  delay 20
  fadescreen FADE_TO_WHITE
  setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
  setflag FLAG_IS_INTRO_COMPLETED
  delay 85
  special RemoveCameraObject
  warpsilent MAP_KAILO_TOWN_PLAYERS_HOUSE_2F, 1, 5
  waitstate
  release
  return

KailoTownFake_Movement_Intro_CameraSetup::
  player_run_left
  player_run_left
  player_run_left
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  player_run_down
  step_end

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
  emote_exclamation_mark
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
