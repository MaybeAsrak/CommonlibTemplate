#pragma once

#include <RE/Skyrim.h>
#include <SKSE/SKSE.h>
//#include <FileName.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <PerkEntryPointExtenderAPI.h>

#define ERROR(message, ...) SKSE::log::error(message, ##__VA_ARGS__)
#define INFO(message, ...) SKSE::log::info(message, ##__VA_ARGS__)
#define TRACE(message, ...) SKSE::log::trace(message, ##__VA_ARGS__)
#define WARN(message, ...) SKSE::log::warn(message, ##__VA_ARGS__)
namespace logger = SKSE::log;

namespace stl {
    using namespace SKSE::stl;
    template <std::integral T, std::size_t N>
    void safe_write(std::uintptr_t a_dst, const std::array<T, N>& a_data) {
        REL::safe_write(a_dst, a_data.data(), a_data.size() * sizeof(T));
    }

    template <class T>
    void write_call(std::uintptr_t a_source) {
        SKSE::AllocTrampoline(14);
        auto& trampoline = SKSE::GetTrampoline();
        trampoline.write_call<5>(a_source, T::Call);
    }
    template <class T>
    void write_thunk_call(std::uintptr_t a_src) {
        SKSE::AllocTrampoline(14);

        auto& trampoline = SKSE::GetTrampoline();
        T::func = trampoline.write_call<5>(a_src, T::thunk);
    }

    //template <class F, std::size_t idx, class T>
    //void write_vfunc() {
    //    REL::Relocation<std::uintptr_t> vtbl{F::VTABLE[0]};
    //    T::func = vtbl.write_vfunc(idx, T::thunk);
    //}
    template <class F, std::size_t idx, class T, std::size_t x = 0>
    void write_vfunc() {
        REL::Relocation<std::uintptr_t> vtbl{F::VTABLE[x]};
        T::func = vtbl.write_vfunc(idx, T::thunk);
    }
    template <std::size_t idx, class T>
    void write_vfunc(REL::VariantID id) {
        REL::Relocation<std::uintptr_t> vtbl{id};
        T::func = vtbl.write_vfunc(idx, T::thunk);
    }
}



//namespace stl
//{ 
//    using namespace SKSE::stl;
//
//    template <class T, std::size_t index, class U>
//    void write_vfunc()
//    {
//       REL::Relocation VTABLE{ T::VTABLE[0] };
//       U::Callback = VTABLE.write_vfunc(index, U::Call);
//    }
//   
//    template <class T>
//    void write_vfunc_call(std::uintptr_t a_source)
//    {
//        auto& trampoline = SKSE::GetTrampoline();
//        T::Callback = *reinterpret_cast<std::uintptr_t*>(trampoline.write_call<6>(a_source, T::Call));
//    }
//
//    template <class T>
//    void write_thunk_call(std::uintptr_t a_source)
//    {
//        auto& trampoline = SKSE::GetTrampoline();
//        T::Callback = trampoline.write_call<5>(a_source, T::Call);
//    }
//}
