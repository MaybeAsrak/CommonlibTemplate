#include "Settings.h"

void Settings::Load()
{
	// Messagebox



	try {
		//const auto settings = toml::parse(TOML_PATH);
		const auto settings = toml::parse(TOML_PATH);

		auto ToggleHotkey1 = toml::find<int>(settings, "ToggleHotkey1");



	}
	catch ([[maybe_unused]] const toml::syntax_error& error) {
		// SKSE::stl::report_and_error(std::format("Settings::Load ~ Failed to parse TOML! <{}>", error.what()));
		stl::report_and_error(std::format("Settings::Load ~ Failed to parse TOML! <{}>", error.what()));

	}
}

Settings::Settings() : toggle(true) {}

bool Settings::GetToggle() const
{
	return toggle;
}

void Settings::SetToggle(bool a_value)
{
	toggle = a_value;
}