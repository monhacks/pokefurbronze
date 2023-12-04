KailoTown_PlayersHouse_2F_MapScripts::
	.byte 0

KailoTown_PlayersHouse_2F_EventScript_Bed::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_WantSleep, MSGBOX_YESNO
  goto_if_eq VAR_RESULT, YES, KailoTown_PlayersHouse_2F_EventScript_Sleep
	goto_if_eq VAR_RESULT, NO, KailoTown_PlayersHouse_2F_EventScript_NoSleep
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_Sleep::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_WentSleep
  closemessage
  call EventScript_OutOfCenterPartyHeal
  msgbox KailoTown_PlayersHouse_2F_Text_Yawn
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_NoSleep::
  msgbox KailoTown_PlayersHouse_2F_Text_TooEarly
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_GBA::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_GBA
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_TV::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_TV
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_NES::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_PlayNES, MSGBOX_YESNO
  goto_if_eq VAR_RESULT, YES, KailoTown_PlayersHouse_2F_EventScript_Play
  goto_if_eq VAR_RESULT, NO, KailoTown_PlayersHouse_2F_EventScript_NoPlay
  closemessage
  release
  end

KailoTown_PlayersHouse_2F_EventScript_Play::
  playse SE_PC_ON
  message KailoTown_PlayersHouse_2F_Text_NESOn
  waitmessage
  delay 50
  closemessage
  applymovement OBJ_EVENT_ID_PLAYER, KailoTown_PlayersHouse_2F_Movement_PlayNES
  waitmovement 0
  fadescreen FADE_TO_BLACK
  delay 85
  delay 85
  fadescreen FADE_FROM_BLACK
  message KailoTown_PlayersHouse_2F_Text_NoRival
  waitmessage
  delay 85
  closemessage
  applymovement OBJ_EVENT_ID_PLAYER, KailoTown_PlayersHouse_2F_Movement_EndNES
  waitmovement 0
  playse SE_PC_OFF
  release
  end

KailoTown_PlayersHouse_2F_Movement_PlayNES::
  walk_right
  walk_down
  face_up
  step_end

KailoTown_PlayersHouse_2F_Movement_EndNES::
  walk_up
  walk_left
  face_up
  step_end

KailoTown_PlayersHouse_2F_EventScript_NoPlay::
  release
  end

KailoTown_PlayersHouse_2F_EventScript_Image::
  lock
  msgbox KailoTown_PlayersHouse_2F_Text_Image
  closemessage
  release
  end
