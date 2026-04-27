#pragma once

class Settings
{
public:
	static void Load();
	//inline static int ToggleHotkey1 = 38;
    int ToggleHotkey1 = 38;

    [[nodiscard]] static Settings* GetSingleton()
    {
        static Settings singleton;
        return std::addressof(singleton);
    }

    [[nodiscard]] bool GetToggle() const;
    void SetToggle(bool a_value);
private:
	static inline std::filesystem::path TOML_PATH = { L"Data\\SKSE\\Plugins\\SCO.toml" };
    Settings();
    Settings(const Settings&) = delete;
    Settings(Settings&&) = delete;

    ~Settings() = default;

    Settings& operator=(const Settings&) = delete;
    Settings& operator=(Settings&&) = delete;
    //int ToggleHotkey1 = 38;

    std::atomic_bool toggle;
};