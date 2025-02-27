#pragma once
#ifndef ES_CORE_SETTINGS_H
#define ES_CORE_SETTINGS_H

#include <map>
#include <string>
#include <vector>

#define DEFINE_BOOL_SETTING(name) static bool name() { return Settings::getInstance()->getBool(#name); }
#define DEFINE_STRING_SETTING(name) static std::string name() { return Settings::getInstance()->getString(#name); }

//This is a singleton for storing settings.
class Settings
{
public:
	static Settings* getInstance();

	void loadFile();
	bool saveFile();

	//You will get a warning if you try a get on a key that is not already present.
	bool getBool(const std::string& name);
	int getInt(const std::string& name);
	float getFloat(const std::string& name);
	std::string getString(const std::string& name);

	bool setBool(const std::string& name, bool value);
	bool setInt(const std::string& name, int value);
	bool setFloat(const std::string& name, float value);
	bool setString(const std::string& name, const std::string& value);

	std::map<std::string, std::string>& getStringMap() { return mStringMap; }

	static bool DebugText;
	static bool DebugImage;
	static bool DebugGrid;

	DEFINE_BOOL_SETTING(HiddenSystemsShowGames)
	DEFINE_STRING_SETTING(HiddenSystems)

private:
	static Settings* sInstance;

	Settings();

	//Clear everything and load default values.
	void setDefaults();

	std::map<std::string, bool> mBoolMap;
	std::map<std::string, int> mIntMap;
	std::map<std::string, float> mFloatMap;
	std::map<std::string, std::string> mStringMap;

	bool mWasChanged;

	std::map<std::string, bool> mDefaultBoolMap;
	std::map<std::string, int> mDefaultIntMap;
	std::map<std::string, float> mDefaultFloatMap;
	std::map<std::string, std::string> mDefaultStringMap;
};

#endif // ES_CORE_SETTINGS_H
