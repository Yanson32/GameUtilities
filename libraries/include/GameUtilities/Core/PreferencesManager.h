#ifndef GAMEUTILITIES_PREFERENCES_MANAGER_H
#define GAMEUTILITIES_PREFERENCES_MANAGER_H
/*********************************************************************************//**
*	@author	Wayne J Larson Jr.
* @date 4/9/2022
* @description This class is used to read and write preferences.
*************************************************************************************/
#include "GameUtilities/Core/String.h"
#include "core_export.h"
namespace GU
{
  namespace Core
  {
    class CORE_EXPORT PreferencesManager
    {
        public:
            /*********************************************************************************//**
            *	@brief: Constructor
            * @param: path is the full path to the preferences file
            *************************************************************************************/
            PreferencesManager(const GU::Core::String &path);


            /*********************************************************************************//**
            *	@brief: This function writes an int value to the preferences file.
            * @param: name is a unique identifyer for the data.
            * @param: data is the data to be written to the preferences file.
            *************************************************************************************/
            void write(const GU::Core::String &name, const int &data);


            /*********************************************************************************//**
            *	@brief: This function writes a float value to the preferences file.
            * @param: name is a unique identifyer for the data.
            * @param: data is the data to be written to the preferences file.
            *************************************************************************************/
    	      void write(const GU::Core::String &name, const float &data);


            /*********************************************************************************//**
            *	@brief: This function writes a GU::Core::String value to the preferences file.
            * @param: name is a unique identifyer for the data.
            * @param: data is the data to be written to the preferences file.
            *************************************************************************************/
    	      void write(const GU::Core::String &name, const GU::Core::String &data);


            /*********************************************************************************//**
            *	@brief:  This function reads an int value from the preferences file.
            * @param:  name is a unique identifyer for the data.
            * @param:  defaultValue is the value to be returned if the value could not
            *          be read from the preferences file.
            * @return: The value read from the preferences file or the default value
            *          if the value could not be read.
            *************************************************************************************/
            int read(const GU::Core::String &name, const int &defaultValue);


            /*********************************************************************************//**
            *	@brief:  This function reads an float value from the preferences file.
            * @param:  name is a unique identifyer for the data.
            * @param:  defaultValue is the value to be returned if the value could not
            *          be read from the preferences file.
            * @return: The value read from the preferences file or the default value
            *          if the value could not be read.
            *************************************************************************************/
    	      float read(const GU::Core::String &name, const float &defautValue);


            /*********************************************************************************//**
            *	@brief:  This function reads an GU::Core::String value from the preferences file.
            * @param:  name is a unique identifyer for the data.
            * @param:  defaultValue is the value to be returned if the value could not
            *          be read from the preferences file.
            * @return: The value read from the preferences file or the default value
            *          if the value could not be read.
            *************************************************************************************/
    	      GU::Core::String read(const GU::Core::String &name, const GU::Core::String &defaultValue);


            /*********************************************************************************//**
            *	@brief: Destructor
            *************************************************************************************/
    	      ~PreferencesManager();
        private:
    	class Impl;
    	Impl *pimpl = nullptr;
    };
  }
}
#endif
