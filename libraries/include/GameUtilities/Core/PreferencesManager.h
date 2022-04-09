#ifndef GAMEUTILITIES_PREFERENCES_MANAGER_H
#define GAMEUTILITIES_PREFERENCES_MANAGER_H
#include "GameUtilities/Core/String.h"
#include "core_export.h"

class CORE_EXPORT PreferencesManager 
{
    public:
        PreferencesManager(const GU::Core::String &path);
        void write(const GU::Core::String &name, const int &data);
	void write(const GU::Core::String &name, const float &data);
	void write(const GU::Core::String &name, const GU::Core::String &data);
        int read(const GU::Core::String &name, const int &defaultValue);
	float read(const GU::Core::String &name, const float &defautValue);
	GU::Core::String read(const GU::Core::String &name, const GU::Core::String &defaultValue);
	~PreferencesManager(); 
    private:
	class Impl;
	Impl *pimpl = nullptr;
};
#endif

