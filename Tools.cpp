#include "Tools.h"

namespace sjdTools
{
    string camelCase(string sInput)
    {
        string s = sInput;
        bool cap = true;
        for(unsigned int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]) && cap == true)
            {
                s[i] = toupper(s[i]);
                cap = false;
            }
            else if (isspace(s[i]))
            {  
                cap = true;
            }
        }
        return s;
    }

    string formatQLDate(Date date) 
    {
        return lexical_cast<string>(date.dayOfMonth()) + "/" + 
               lexical_cast<string>(date.month()) + "/" + 
               lexical_cast<string>(date.year());
    }

    ErrorTracking::ErrorTracking(string classNameInput)
    {
        errorMessages = vector<string>();
        hasErrors = false;
        className = classNameInput;
    }

   string ErrorTracking::getClassName() 
   {
      return className;
   }

   void ErrorTracking::clearErrorMessages()
    {
        hasErrors = false;
        errorMessages.clear();
    }

    void ErrorTracking::populateErrorMessage(string msg)
    {
        errorMessages.push_back(className + ": " + msg);
        hasErrors = true;
    }

    void ErrorTracking::populateErrorMessage(vector<string> msgs)
    {
        errorMessages.push_back(className);
        for (vector<string>::iterator it = msgs.begin(); it != msgs.end(); ++it)
        {
            errorMessages.push_back(*it);
        }
        hasErrors = true;
    }

    bool ErrorTracking::getHasErrors() const
    {
        return hasErrors;
    }

    vector<string> ErrorTracking::getErrorMessages() const 
    {
        return errorMessages;
    }

   string ErrorTracking::getErrorMessagesAsString() const
   {
      string allErrorMessages = className + ": ";
      for (size_t i = 0; i < errorMessages.size(); ++i) {
         allErrorMessages = allErrorMessages + errorMessages[i];
            if (i < errorMessages.size() - 1)
            {
                allErrorMessages = allErrorMessages + ", ";
            }
      }
      return allErrorMessages;
   }

}