KailoTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, KailoTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

KailoTown_PokemonCenter_1F_OnTransition::
    setrespawn SPAWN_KAILO_TOWN
	end

KailoTown_PokemonCenter_1F_EventScript_Doctor::
	lock
	faceplayer
	call EventScript_PkmnCenterNurse
	release
	end
