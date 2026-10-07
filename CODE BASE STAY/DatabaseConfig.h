#pragma once

using namespace System;
using namespace System::IO;
using namespace MySql::Data::MySqlClient;

namespace CODEBASESTAY {

    public ref class DatabaseConfig abstract sealed
    {
    public:
        static String^ GetConnectionString()
        {
            String^ path = Path::Combine(
                AppDomain::CurrentDomain->BaseDirectory,
                "database.config");

            if (!File::Exists(path))
            {
                throw gcnew Exception(
                    "Database settings file not found: " + path);
            }

            MySqlConnectionStringBuilder^ settings =
                gcnew MySqlConnectionStringBuilder(
                    File::ReadAllText(path)->Trim());

            return settings->ConnectionString;
        }
    };
}