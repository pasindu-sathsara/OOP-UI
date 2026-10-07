#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace CODEBASESTAY {

    public ref class HotelService
    {
    public:
        String^ TestConnection()
        {
            MySqlConnectionStringBuilder^ settings =
                gcnew MySqlConnectionStringBuilder();

            settings->Server = "127.0.0.1";
            settings->Port = 3306;
            settings->Database = "hotelmanagement_sys";
            settings->UserID = "root";
            settings->Password = "1234";

            MySqlConnection^ connection =
                gcnew MySqlConnection(settings->ConnectionString);

            try
            {
                connection->Open();

                MySqlCommand^ command = gcnew MySqlCommand(
                    "SELECT COUNT(*) FROM room", connection);

                try
                {
                    int count = Convert::ToInt32(
                        command->ExecuteScalar());

                    return String::Format(
                        "Database connected!\nRooms in database: {0}",
                        count);
                }
                finally
                {
                    delete command;
                }
            }
            finally
            {
                delete connection;
            }
        }

    void AddRoom(int roomNumber, String^ roomType,
        Decimal price, String^ status)
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlCommand^ command = gcnew MySqlCommand(
                "INSERT INTO room (Room_id, type, price, status) "
                "VALUES (@id, @type, @price, @status)",
                connection);

            try
            {
                command->Parameters->Add(
                    "@id", MySqlDbType::Int32)->Value = roomNumber;

                command->Parameters->Add(
                    "@type", MySqlDbType::VarChar)->Value = roomType;

                // Your current database stores price as text.
                command->Parameters->Add(
                    "@price", MySqlDbType::VarChar)->Value =
                    price.ToString(
                        System::Globalization::CultureInfo::InvariantCulture);

                command->Parameters->Add(
                    "@status", MySqlDbType::VarChar)->Value = status;

                command->ExecuteNonQuery();
            }
            finally
            {
                delete command;
            }
        }
        finally
        {
            delete connection;
        }
    }

    bool UpdateRoom(int roomNumber, String^ roomType,
        Decimal price, String^ status)
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlCommand^ command = gcnew MySqlCommand(
                "UPDATE room SET type=@type, price=@price, "
                "status=@status WHERE Room_id=@id",
                connection);

            try
            {
                command->Parameters->Add(
                    "@id", MySqlDbType::Int32)->Value = roomNumber;

                command->Parameters->Add(
                    "@type", MySqlDbType::VarChar)->Value = roomType;

                command->Parameters->Add(
                    "@price", MySqlDbType::VarChar)->Value =
                    price.ToString(
                        System::Globalization::CultureInfo::InvariantCulture);

                command->Parameters->Add(
                    "@status", MySqlDbType::VarChar)->Value = status;

                return command->ExecuteNonQuery() > 0;
            }
            finally
            {
                delete command;
            }
        }
        finally
        {
            delete connection;
        }
    }

    bool DeleteRoom(int roomNumber)
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlCommand^ command = gcnew MySqlCommand(
                "DELETE FROM room WHERE Room_id=@id",
                connection);

            try
            {
                command->Parameters->Add(
                    "@id", MySqlDbType::Int32)->Value = roomNumber;

                return command->ExecuteNonQuery() > 0;
            }
            finally
            {
                delete command;
            }
        }
        finally
        {
            delete connection;
        }
    }

    System::Data::DataTable^ GetRooms()
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(
                "SELECT Room_id, type, price, status "
                "FROM room ORDER BY Room_id",
                connection);

            try
            {
                System::Data::DataTable^ table =
                    gcnew System::Data::DataTable();

                adapter->Fill(table);
                return table;
            }
            finally
            {
                delete adapter;
            }
        }
        finally
        {
            delete connection;
        }
    }

    int CreateBooking(String^ name, String^ phone, String^ nic,
        int roomNumber, DateTime checkIn, DateTime checkOut)
    {
        name = name->Trim();
        phone = phone->Trim();
        nic = nic->Trim();
        checkIn = checkIn.Date;
        checkOut = checkOut.Date;

        if (String::IsNullOrWhiteSpace(name) || name->Length > 100 ||
            String::IsNullOrWhiteSpace(phone) || phone->Length > 20 ||
            String::IsNullOrWhiteSpace(nic) || nic->Length > 20)
            throw gcnew Exception("Enter a valid name, phone number and NIC.");

        if (roomNumber <= 0 || checkOut <= checkIn)
            throw gcnew Exception(
                "Enter a valid room number and a checkout date after check-in.");

        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlTransaction^ transaction = connection->BeginTransaction();
            MySqlCommand^ command = connection->CreateCommand();
            command->Transaction = transaction;

            try
            {
                // Lock the room while checking and saving its booking.
                command->CommandText =
                    "SELECT price FROM room WHERE Room_id=@room FOR UPDATE";
                command->Parameters->AddWithValue("@room", roomNumber);

                Object^ roomPrice = command->ExecuteScalar();

                if (roomPrice == nullptr || roomPrice == DBNull::Value)
                    throw gcnew Exception("Room not found or has no price.");

                Decimal price;
                if (!Decimal::TryParse(
                    Convert::ToString(roomPrice),
                    System::Globalization::NumberStyles::Number,
                    System::Globalization::CultureInfo::InvariantCulture,
                    price) || price <= Decimal(0))
                    throw gcnew Exception("This room has an invalid price.");

                command->CommandText =
                    "SELECT reservation_id FROM reservation "
                    "WHERE room_id=@room "
                    "AND (status IS NULL OR status <> 'Cancelled') "
                    "AND check_in < @out AND check_out > @in "
                    "LIMIT 1 FOR UPDATE";

                command->Parameters->Add(
                    "@in", MySqlDbType::Date)->Value = checkIn;
                command->Parameters->Add(
                    "@out", MySqlDbType::Date)->Value = checkOut;

                if (command->ExecuteScalar() != nullptr)
                    throw gcnew Exception(
                        "This room is already booked for those dates.");

                command->Parameters->Clear();
                command->CommandText =
                    "INSERT INTO guest (Guest_name, phone, nic) "
                    "VALUES (@name, @phone, @nic)";

                command->Parameters->AddWithValue("@name", name);
                command->Parameters->AddWithValue("@phone", phone);
                command->Parameters->AddWithValue("@nic", nic);
                command->ExecuteNonQuery();

                int guestId = Convert::ToInt32(command->LastInsertedId);
                int nights = (checkOut - checkIn).Days;
                Decimal total = Decimal::Multiply(price, Decimal(nights));

                command->Parameters->Clear();
                command->CommandText =
                    "INSERT INTO reservation "
                    "(guest_id, room_id, pacage_id, numberOfnigths, "
                    "total_amount, status, check_in, check_out) "
                    "VALUES (@guest, @room, NULL, @nights, "
                    "@total, 'Confirmed', @in, @out)";

                command->Parameters->AddWithValue("@guest", guestId);
                command->Parameters->AddWithValue("@room", roomNumber);
                command->Parameters->AddWithValue("@nights", nights);
                command->Parameters->AddWithValue(
                    "@total", total.ToString(
                        System::Globalization::CultureInfo::InvariantCulture));
                command->Parameters->Add(
                    "@in", MySqlDbType::Date)->Value = checkIn;
                command->Parameters->Add(
                    "@out", MySqlDbType::Date)->Value = checkOut;

                command->ExecuteNonQuery();

                int bookingId = Convert::ToInt32(command->LastInsertedId);
                transaction->Commit();
                return bookingId;
            }
            catch (Exception^)
            {
                try { transaction->Rollback(); }
                catch (Exception^) {}
                throw;
            }
            finally
            {
                delete command;
                delete transaction;
            }
        }
        finally
        {
            delete connection;
        }
    }

    System::Data::DataTable^ GetBookings()
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(
                "SELECT r.reservation_id AS booking_id, "
                "g.Guest_name AS guest_name, r.room_id, "
                "r.check_in, r.check_out, "
                "r.numberOfnigths AS nights, "
                "r.total_amount, r.status "
                "FROM reservation r "
                "JOIN guest g ON g.guest_id = r.guest_id "
                "ORDER BY r.reservation_id DESC",
                connection);

            try
            {
                System::Data::DataTable^ table =
                    gcnew System::Data::DataTable();

                adapter->Fill(table);
                return table;
            }
            finally
            {
                delete adapter;
            }
        }
        finally
        {
            delete connection;
        }
    }

    array<int>^ GetDashboardCounts()
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlCommand^ command = connection->CreateCommand();

            try
            {
                array<int>^ counts = gcnew array<int>(3);

                command->CommandText = "SELECT COUNT(*) FROM room";
                counts[0] = Convert::ToInt32(command->ExecuteScalar());

                command->CommandText =
                    "SELECT COUNT(DISTINCT room_id) FROM reservation "
                    "WHERE status = 'Confirmed' "
                    "AND check_in <= CURDATE() "
                    "AND check_out > CURDATE()";

                counts[1] = Convert::ToInt32(command->ExecuteScalar());

                command->CommandText =
                    "SELECT COUNT(*) FROM reservation";

                counts[2] = Convert::ToInt32(command->ExecuteScalar());

                return counts;
            }
            finally
            {
                delete command;
            }
        }
        finally
        {
            delete connection;
        }
    }


    System::Data::DataTable^ GetRecentBookings()
    {
        MySqlConnectionStringBuilder^ settings =
            gcnew MySqlConnectionStringBuilder();

        settings->Server = "127.0.0.1";
        settings->Port = 3306;
        settings->Database = "hotelmanagement_sys";
        settings->UserID = "root";
        settings->Password = "1234";

        MySqlConnection^ connection =
            gcnew MySqlConnection(settings->ConnectionString);

        try
        {
            connection->Open();

            MySqlDataAdapter^ adapter = gcnew MySqlDataAdapter(
                "SELECT g.Guest_name AS guest_name, "
                "r.total_amount AS amount, r.room_id AS room "
                "FROM reservation r "
                "JOIN guest g ON g.guest_id = r.guest_id "
                "ORDER BY r.reservation_id DESC LIMIT 5",
                connection);

            try
            {
                System::Data::DataTable^ table =
                    gcnew System::Data::DataTable();

                adapter->Fill(table);
                return table;
            }
            finally
            {
                delete adapter;
            }
        }
        finally
        {
            delete connection;
        }
    }

    };

}