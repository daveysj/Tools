#ifndef SBSATOOLS_INCLUDED
#define SBSATOOLS_INCLUDED

#pragma once

#include <boost/lexical_cast.hpp> 
#include <ql\time\date.hpp>
#include <string>
#include <vector>

using namespace QuantLib;
using namespace std;
using namespace boost;

/*======================================================================================
Overview

=======================================================================================*/

namespace sjdTools
{
    string camelCase(string sInput);

    string formatQLDate(Date date);

    class ErrorTracking 
    {
    public:
        ErrorTracking(string className);

        string getClassName();

        void clearErrorMessages();
        void populateErrorMessage(string msg);
        void populateErrorMessage(vector<string> msg);
        bool getHasErrors() const;
        vector<string> getErrorMessages() const;
        string getErrorMessagesAsString() const;

    private:
        bool hasErrors;
        vector<string> errorMessages;
        string className;
    };
}

#endif