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




	static void Install() {

		if SKYRIM_REL_CONSTEXPR(REL::Module::IsAE()) {
            INFO("Hello, AE user {}!", SKSE::PluginDeclaration::GetSingleton()->GetAuthor());
			REL::Relocation<std::uintptr_t> targetDual{RELOCATION_ID(0, 38762), REL::Relocate(0x0, 0x92)};
			REL::safe_fill(targetDual.address(), REL::NOP, 0xD);
            REL::Relocation<std::uintptr_t> DualCastCheckHookB{RELOCATION_ID(0, 38762), REL::Relocate(0x0, 0xDA)};
        stl::write_thunk_call<DualCastPerkCheck>(DualCastCheckHookB.address());

		}
        REL::Relocation<std::uintptr_t> DualCastSpellCheck{RELOCATION_ID(37816, 38765), REL::Relocate(0x8D, 0x8D)};
        REL::safe_fill(DualCastSpellCheck.address(), REL::NOP, 0x9);

        REL::Relocation<std::uintptr_t> DualCastCheckHookA{RELOCATION_ID(37816, 38765), REL::Relocate(0xCD, 0xCD)};
        stl::write_thunk_call<DualCastPerkCheck>(DualCastCheckHookA.address());




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

    messaging_interface->RegisterListener(HandleMessage);

    return true;
}
