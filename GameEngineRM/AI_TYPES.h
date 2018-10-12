#pragma once

#ifndef	  __AI_TYPES_H_
#define	  __AI_TYPES_H_
#endif /* __AI_TYPES_H_ */

namespace GameEngineM
{

	enum class AI_TYPES
	{
		AI_NONE,
		AI_WANDER,
		AI_TRACK_TARGET,
		AI_CONSUME,
		AI_BREED_WILLING,
		AI_BREED_ATTEMPT,
		AI_BREED_OFFSPRING,
		AI_BORN,
		AI_TRACK_PARENT,
		AI_FOLLOW_PARENT,
		AI_ATTACK_MELEE,
		AI_ATTACK_RANGED,
		AI_ATTACK_MAGIC,
		AI_ATTACK_AOE,
		AI_ATTACK_SPECIAL,
		AI_EVADE_MELEE,
		AI_EVADE_RANGED,
		AI_EVADE_MAGIC,
		AI_EVADE_AOE,
		AI_EVADE_SPECIAL,
		AI_TAUNT,
		AI_DRINK,
		AI_AGGRESSIVE,
		AI_DEFENSIVE,
		AI_DEFICATE,
		AI_BUTCHER,
		AI_ROAM,
		AI_GATHER,
		AI_FARM,
		AI_HARVEST,
		AI_PICKUP,
		AI_SOW,
		AI_HEAL

	};

}