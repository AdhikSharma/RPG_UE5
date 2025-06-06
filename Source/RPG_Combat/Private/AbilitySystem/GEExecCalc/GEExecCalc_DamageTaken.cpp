// Adhik Sharma All right reserved


#include "AbilitySystem/GEExecCalc/GEExecCalc_DamageTaken.h"
#include "AbilitySystem/WarriorAttributeSet.h"
#include "WarriorGameplayTags.h"

#include "WarriorDebugHelper.h"

struct FWarriorDamageCapture 
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	

	FWarriorDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UWarriorAttributeSet, DamageTaken, Target, false)
	}
};

static const FWarriorDamageCapture& GetWarriorDamageCapture() 
{
	static FWarriorDamageCapture WarriorDamageCapture;
	return WarriorDamageCapture;
}

UGEExecCalc_DamageTaken::UGEExecCalc_DamageTaken()
{
	/**Slow way of doing capture**/
	//FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(
	//	UWarriorAttributeSet::StaticClass(),
	//	GET_MEMBER_NAME_CHECKED(UWarriorAttributeSet,AttackPower)
	//);
	//
	//FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(
	//	AttackPowerProperty,
	//	EGameplayEffectAttributeCaptureSource::Source,
	//	false
	//);

	//RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);

	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetWarriorDamageCapture().DamageTakenDef);
}

void UGEExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetWarriorDamageCapture().AttackPowerDef,
		EvaluateParameters,
		SourceAttackPower
	);

	//Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower,FColor::Green);

	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;

	for (const TPair<FGameplayTag,float>& TagMagnitued : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitued.Key.MatchesTagExact(WarriorGameplayTags::Shared_SetByCaller_BaseDamage)) 
		{
			BaseDamage = TagMagnitued.Value;
			//Debug::Print(TEXT("BaseDamage"), BaseDamage, FColor::Green);
		}

		if(TagMagnitued.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitued.Value;
			//Debug::Print(TEXT("UsedLightAttackComboCount"), UsedLightAttackComboCount, FColor::Green);
		}

		if (TagMagnitued.Key.MatchesTagExact(WarriorGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitued.Value;
			//Debug::Print(TEXT("UsedHeavyAttackComboCount"), UsedHeavyAttackComboCount, FColor::Green);
		}
	}

	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(
		GetWarriorDamageCapture().DefensePowerDef,
		EvaluateParameters,
		TargetDefensePower
	);

	//Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower, FColor::Green);

	if (UsedLightAttackComboCount!=0) 
	{
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * 0.05f + 1.f;
		BaseDamage *= DamageIncreasePercentLight;
		//Debug::Print(TEXT("Scaled Light Attack Damage"), BaseDamage, FColor::Green);
	}

	if (UsedHeavyAttackComboCount != 0)
	{
		const float DamageIncreasePercentHeavy = (UsedHeavyAttackComboCount - 1) * 0.15f + 1.f;
		BaseDamage *= UsedHeavyAttackComboCount;
		//Debug::Print(TEXT("Scaled Heavy Attack Damage"), BaseDamage, FColor::Green);
	}

	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;

	Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone, FColor::Green);

	if (FinalDamageDone > 0.f) 
	{
		OutExecutionOutput.AddOutputModifier(
			FGameplayModifierEvaluatedData(
				GetWarriorDamageCapture().DamageTakenProperty,
				EGameplayModOp::Override,
				FinalDamageDone
			)
		);
	}

}
