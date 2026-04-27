#include <PerkEntryPointExtenderAPI.h>









//Mod 1:
//
//Spell fusion
//
//spell + spell (+ shout)
//
//spell + keyword (+ shout)
//
//spell + spell (+ shout keyword?)
//
//create a map that is {spell to cast, spell 1, spell 2, shout*} or one that is {spell to cast, spell 1, keyword 2, shout*} and then you iterate through and reorder for priority?
//
//need to get hooks for unlocked dual casting, override spell, override dual cast, override cost 
//
//Shout could control dual casting or modifier benefits

static void CastSpellImpl(RE::ActorMagicCaster* a_AMC) {
    // SE: 0x3E1450, AE: 0x3FC5A0, VR: ---
    using func_t = decltype(&CastSpellImpl);
    REL::Relocation<func_t> func{REL::RelocationID(34445, 34445)};
    func(a_AMC);
}
static RE::ActorValue LookupActorValueByName(const char* av_name) {
    // SE: 0x3E1450, AE: 0x3FC5A0, VR: ---
    using func_t = decltype(&LookupActorValueByName);
    REL::Relocation<func_t> func{REL::RelocationID(26570, 27203)};
    return func(av_name);
}


struct Hooks {
    struct DualCastPerkCheck {
        static void thunk(void* entry_point, RE::Actor* caster, RE::MagicItem* a_spell, void* outbound) {
            //bool testbool;
            //func(entry_point, caster, a_spell, &outbound);
            //if (testbool == true) {
            //    if (caster->GetActorRuntimeData().selectedSpells[0] == caster->GetActorRuntimeData().selectedSpells[1]) {
            //        *outbound = true;
            //    }
            //    else {
            //        float dualcast = 0.0f;
            //        RE::HandleEntryPoint(RE::PerkEntryPoint::kCanDualCastSpell, caster, &dualcast, "DCO", 3, {a_spell});
            //        if (dualcast > 0.0f) {
            //            //*outbound = true; 
            //            bool* boolPtr = static_cast<bool*>(outbound);
            //*boolPtr = true; 
            //        }
            //        else {
            float testfloat = 0.0f;
            RE::BGSEntryPoint::HandleEntryPoint(RE::BGSPerkEntry::EntryPoint::kCanDualCastSpell, caster, a_spell, &testfloat);
                        //func(entry_point, caster, a_spell, &testfloat);
                        if (testfloat == 0.0f) {

                            bool* boolPtr = static_cast<bool*>(outbound);
                            *boolPtr = true;
                        }
                        //*outbound = false; // could have an additional failsafe here?
                    //}
            //    }


            //}

        }

        static inline REL::Relocation<decltype(thunk)> func;
    };

    struct CancelSpellHook {
        static void thunk(RE::MagicCaster* MC) {
            //bool testbool;
            //func(entry_point, caster, a_spell, &outbound);
            //if (testbool == true) {
            //    if (caster->GetActorRuntimeData().selectedSpells[0] == caster->GetActorRuntimeData().selectedSpells[1]) {
            //        *outbound = true;
            //    }
            //    else {
            //        float dualcast = 0.0f;
            //        RE::HandleEntryPoint(RE::PerkEntryPoint::kCanDualCastSpell, caster, &dualcast, "DCO", 3, {a_spell});
            //        if (dualcast > 0.0f) {
            //            //*outbound = true; 
            //            bool* boolPtr = static_cast<bool*>(outbound);
            //*boolPtr = true; 
            //        }
            //        else {
            RE::ConsoleLog::GetSingleton()->Print("test buffer");

            //*outbound = false; // could have an additional failsafe here?
        //}
//    }


//}

        }
        static inline REL::Relocation<decltype(thunk)> func;
    };

    struct InitiateSpellHook {
        static void thunk(RE::ActorMagicCaster* a_AMC, RE::MagicItem* spell, RE::Actor* a_PC, bool a_arg4) {
            //bool testbool;
            //func(entry_point, caster, a_spell, &outbound);
            //if (testbool == true) {
            //    if (caster->GetActorRuntimeData().selectedSpells[0] == caster->GetActorRuntimeData().selectedSpells[1]) {
            //        *outbound = true;
            //    }
            //    else {
            //        float dualcast = 0.0f;
            //        RE::HandleEntryPoint(RE::PerkEntryPoint::kCanDualCastSpell, caster, &dualcast, "DCO", 3, {a_spell});
            //        if (dualcast > 0.0f) {
            //            //*outbound = true; 
            //            bool* boolPtr = static_cast<bool*>(outbound);
            //*boolPtr = true; 
            //        }
            //        else {
            //if (a_AMC->state.get() == RE::MagicCaster::State::kUnk02) {
            //    RE::ConsoleLog::GetSingleton()->Print("tested buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kReady) {
            //    RE::ConsoleLog::GetSingleton()->Print("testededed buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kNone) {
            //    RE::ConsoleLog::GetSingleton()->Print("butter buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk01) {
            //    RE::ConsoleLog::GetSingleton()->Print("buttering buffer");
            //    if (a_PC->AsActorValueOwner()->GetActorValue(RE::ActorValue::kDestruction) > 30.0f)
            //    {
            //        a_AMC->InterruptCast(true);
            //        RE::ConsoleLog::GetSingleton()->Print("Spaghetti");
            //        //33623, 34401

            //    }

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kCasting) {
            //    RE::ConsoleLog::GetSingleton()->Print("cast");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kCharging) {
            //    RE::ConsoleLog::GetSingleton()->Print("charge");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk07) {
            //    RE::ConsoleLog::GetSingleton()->Print("seven");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk04) {
            //    RE::ConsoleLog::GetSingleton()->Print("four");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk09) {
            //    RE::ConsoleLog::GetSingleton()->Print("nine");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk08) {
            //    RE::ConsoleLog::GetSingleton()->Print("eight");

            //}
            //RE::ConsoleLog::GetSingleton()->Print("test buffer");
            func(a_AMC, spell, a_PC, a_arg4);
        }
        static inline REL::Relocation<decltype(thunk)> func;
    };


    struct SpellCastingHook : Xbyak::CodeGenerator {

        SpellCastingHook(std::uintptr_t a_Function, std::uintptr_t a_Address)
    {
        Xbyak::Label Function;
        Xbyak::Label Return;

        mov(rdx, rbx);
        mov(rcx, rdi);
        call(ptr[rip + Function]);
        jmp(ptr[rip + Return]);

        L(Function);
        dq(a_Function);

        L(Return);
        dq(a_Address + 0x0A);
    }
        static void Call(RE::ActorMagicCaster* a_AMC, RE::ButtonEvent* be) {
            INFO("message here");
            auto a = a_AMC->GetCasterAsActor();
            //a->AsActorValueOwner()->RestoreActorValue(RE::ACTOR_VALUE_MODIFIER::kPermanent, RE::ActorValue::kAlterationPowerModifier, 50.0f);
            RE::ConsoleLog::GetSingleton()->Print("test buffer");
            if (be->HeldDuration() < 1.0f) {
                INFO("my name is: {}", "asrak");
                //if (a_AMC->state.get() == RE::MagicCaster::State::kUnk02) {
                //    RE::ConsoleLog::GetSingleton()->Print("tested buffer");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kReady) {
                //    RE::ConsoleLog::GetSingleton()->Print("testededed buffer");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kNone) {
                //    RE::ConsoleLog::GetSingleton()->Print("butter buffer");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk01) {
                //    RE::ConsoleLog::GetSingleton()->Print("buttering buffer");
                //    if (a->AsActorValueOwner()->GetActorValue(RE::ActorValue::kDestruction) > 30.0f) 
                //    { a_AMC->InterruptCast(true); 
                //    RE::ConsoleLog::GetSingleton()->Print("Spaghetti");
                //    //33623, 34401
                //    
                //    }

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kCasting) {
                //    RE::ConsoleLog::GetSingleton()->Print("cast");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kCharging) {
                //    RE::ConsoleLog::GetSingleton()->Print("charge");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk07) {
                //    RE::ConsoleLog::GetSingleton()->Print("seven");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk04) {
                //    RE::ConsoleLog::GetSingleton()->Print("four");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk09) {
                //    RE::ConsoleLog::GetSingleton()->Print("nine");

                //}
                //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk08) {
                //    RE::ConsoleLog::GetSingleton()->Print("eight");

                //}
            }

        }
    };

    struct FullChargeHook : Xbyak::CodeGenerator {

        FullChargeHook(std::uintptr_t a_Function1, std::uintptr_t a_Address1)
        {
            Xbyak::Label Function1;
            Xbyak::Label Return1;

            mov(rdx, rbx);
            mov(rcx, rdi);
            call(ptr[rip + Function1]);
            jmp(ptr[rip + Return1]);

            L(Function1);
            dq(a_Function1);

            L(Return1);
            dq(a_Address1 + 0x08);
        }
        static void Call(RE::ActorMagicCaster* a_AMC, RE::ButtonEvent* be) {
            INFO("message here");
            auto a = a_AMC->GetCasterAsActor();
            //a->AsActorValueOwner()->RestoreActorValue(RE::ACTOR_VALUE_MODIFIER::kPermanent, RE::ActorValue::kAlterationPowerModifier, 66.6f);
            //RE::ConsoleLog::GetSingleton()->Print("test buffering");
            //if (be->HeldDuration() > 1.0f) {
            //    INFO("my name is: {}", "asrak karsa");

            //    RE::ConsoleLog::GetSingleton()->Print("tested buffer");

            //}
            //if (a_AMC->state.get() == RE::MagicCaster::State::kUnk02) {
            //    RE::ConsoleLog::GetSingleton()->Print("tested buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kReady) {
            //    RE::ConsoleLog::GetSingleton()->Print("testededed buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kNone) {
            //    RE::ConsoleLog::GetSingleton()->Print("butter buffer");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk01) {
            //    RE::ConsoleLog::GetSingleton()->Print("buttering buffer");
                if (a->AsActorValueOwner()->GetActorValue(RE::ActorValue::kDestruction) > 30.0f)
                {
                      a_AMC->StartCastImpl();
                      a->AsActorValueOwner()->SetActorValue(RE::ActorValue::kDestruction)
            //        a_AMC->InterruptCast(true);
            //        RE::ConsoleLog::GetSingleton()->Print("Spaghetti");
            //        //33623, 34401

                }

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kCasting) {
            //    RE::ConsoleLog::GetSingleton()->Print("cast");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kCharging) {
            //    RE::ConsoleLog::GetSingleton()->Print("charge");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk07) {
            //    RE::ConsoleLog::GetSingleton()->Print("seven");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk04) {
            //    RE::ConsoleLog::GetSingleton()->Print("four");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk09) {
            //    RE::ConsoleLog::GetSingleton()->Print("nine");

            //}
            //else if (a_AMC->state.get() == RE::MagicCaster::State::kUnk08) {
            //    RE::ConsoleLog::GetSingleton()->Print("eight");

            //}
            CastSpellImpl(a_AMC);

        }
    };

    struct FinishChargingHook {
        static void thunk(RE::ActorMagicCaster* a_AMC) {
            auto a = a_AMC->GetCasterAsActor();
            auto source = a_AMC->GetCastingSource();


            RE::ConsoleLog::GetSingleton()->Print("FinishCast!");
            func(a_AMC);
            if (a_AMC->currentSpell->GetCastingType() != RE::MagicSystem::CastingType::kConcentration) {
                if (a->AsActorValueOwner()->GetActorValue(RE::ActorValue::kAlterationPowerModifier) > 30.0f) {
                    a_AMC->StartCastImpl();
                }
            }
        }
        static inline REL::Relocation<decltype(thunk)> func;
    };

    struct SecondInterruptHook {
        static void thunk(RE::ActorMagicCaster* a_AMC) {
            auto a = a_AMC->GetCasterAsActor();
            auto source = a_AMC->GetCastingSource();


            RE::ConsoleLog::GetSingleton()->Print("FinishCasting!");
            func(a_AMC);
            //if (a_AMC->currentSpell->GetCastingType() != RE::MagicSystem::CastingType::kConcentration) {
            //    if (a->AsActorValueOwner()->GetActorValue(RE::ActorValue::kAlterationPowerModifier) > 30.0f) {
            //        a_AMC->StartCastImpl();
            //    }
            //}
        }
        static inline REL::Relocation<decltype(thunk)> func;
    };


    struct FindTargetHook {
        static bool thunk(RE::MagicCaster* a_MC, float a_effectivenessMult, std::uint32_t& a_targetCount, RE::TESBoundObject* a_source,
            bool a_loadCast, bool a_adjustOnlyHostileEffectiveness) {

            float toggle = a_MC->GetCasterAsActor()->AsActorValueOwner()->GetActorValue(RE::ActorValue::kAlterationPowerModifier);
            if (a_effectivenessMult <= 0.5f) {
            }



            if (a_adjustOnlyHostileEffectiveness) {
            }
            if (toggle >= 1000) {
                a_effectivenessMult = 1000.0f;
            }

            return func(a_MC, a_effectivenessMult, a_targetCount, a_source, a_loadCast, a_adjustOnlyHostileEffectiveness);
        }
        static inline REL::Relocation<decltype(thunk)> func;
    };

    struct FindTargetsHook {
        static uint32_t* thunk(uint32_t* handle, RE::Projectile::LaunchData* ldata) {
            auto a_MC = ldata->shooter->As<RE::Actor>();
            if (a_MC) {
                float toggle = a_MC->AsActorValueOwner()->GetActorValue(RE::ActorValue::kIllusionPowerModifier);
                if (toggle >= 1000) {
                    ldata->power = ldata->power * 10.0f;
                }

            }
            return func(handle, ldata);
        }
        static inline REL::Relocation<decltype(thunk)> func;
    };

	static void Install() {

		//if SKYRIM_REL_CONSTEXPR(REL::Module::IsAE()) {
  //          INFO("Hello, AE user {}!", SKSE::PluginDeclaration::GetSingleton()->GetAuthor());
		//	REL::Relocation<std::uintptr_t> targetDual{RELOCATION_ID(0, 38762), REL::Relocate(0x0, 0x92)};
		//	REL::safe_fill(targetDual.address(), REL::NOP, 0xD);
  //          REL::Relocation<std::uintptr_t> DualCastCheckHookB{RELOCATION_ID(0, 38762), REL::Relocate(0x0, 0xDA)};
  //      stl::write_thunk_call<DualCastPerkCheck>(DualCastCheckHookB.address());

		//}
  //      REL::Relocation<std::uintptr_t> DualCastSpellCheck{RELOCATION_ID(37816, 38765), REL::Relocate(0x8D, 0x8D)};
  //      REL::safe_fill(DualCastSpellCheck.address(), REL::NOP, 0x9);

  //      REL::Relocation<std::uintptr_t> DualCastCheckHookA{RELOCATION_ID(37816, 38765), REL::Relocate(0xCD, 0xCD)};
  //      stl::write_thunk_call<DualCastPerkCheck>(DualCastCheckHookA.address());

        //REL::Relocation<std::uintptr_t> DualCastCheckHookC{RELOCATION_ID(41362, 42436), REL::Relocate(0xCA, 0xCA)};
        //stl::write_thunk_call<CancelSpellHook>(DualCastCheckHookC.address());

        //stl::write_vfunc<RE::ActorMagicCaster, 0x05, FinishChargingHook, 0>();

        stl::BRANCH5<SpellCastingHook, 5>(RELOCATION_ID(41362, 42436), REL::Relocate(0xC5, 0xC5));
        stl::BRANCH5<FullChargeHook, 3>(RELOCATION_ID(41362, 42436), REL::Relocate(0xE8, 0xE8));

        REL::Relocation<std::uintptr_t> functionc{RELOCATION_ID(33629, 34407), REL::Relocate(0xE9, 0xE4)};
        stl::write_thunk_call<FindTargetHook>(functionc.address());

        REL::Relocation<std::uintptr_t> functionce{RELOCATION_ID(33672, 34452), REL::Relocate(0x377, 0x354)};
        stl::write_thunk_call<FindTargetsHook>(functionce.address());

        REL::Relocation<std::uintptr_t> SecondInterruptHookFunction{RELOCATION_ID(41362, 42436), REL::Relocate(0x182, 0x182)};
        stl::write_thunk_call<SecondInterruptHook>(SecondInterruptHookFunction.address());

        //REL::Relocation<std::uintptr_t> functionInitiate{RELOCATION_ID(41338, 42417), REL::Relocate(0xA8, 0xA8)};
        //stl::write_thunk_call<InitiateSpellHook>(functionInitiate.address());

	}
};


void InitializeLogger()
{
    auto path = SKSE::log::log_directory();
   
    if (!path) { return; }

    const auto plugin = SKSE::PluginDeclaration::GetSingleton();
    *path /= std::format("{}.log", plugin->GetName());

    std::vector<spdlog::sink_ptr> sinks{
        std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true),
        std::make_shared<spdlog::sinks::msvc_sink_mt>()
    };

    auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
   
    logger->set_level(spdlog::level::info);
    logger->flush_on(spdlog::level::info);

    spdlog::set_default_logger(std::move(logger));
    spdlog::set_pattern("[%^%L%$] %v");
}

void HandleMessage(SKSE::MessagingInterface::Message* a_message)
{
    switch (a_message->type) {
    case SKSE::MessagingInterface::kDataLoaded:
        {
            INFO("Hello, {}!", SKSE::PluginDeclaration::GetSingleton()->GetAuthor());
            Hooks::Install();
        }
        break;
    }
}

SKSEPluginLoad(const SKSE::LoadInterface* a_skse)
{
    InitializeLogger();

    SKSE::Init(a_skse);

    const auto messaging_interface = SKSE::GetMessagingInterface();

    if (!messaging_interface) { stl::report_and_fail("Failed to communicate with the messaging interface!"); }
    SKSE::AllocTrampoline(1024);

    messaging_interface->RegisterListener(HandleMessage);

    return true;
}
