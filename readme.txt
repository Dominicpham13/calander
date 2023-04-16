to be able to schedule
    schedule obj
    user input
    output events based on days
        link the schedule to days of the week
    delete schedule

prompt the user:
    getting their schedule
    printing their schedule when asked for it 
        wednesday: dr app
        thursday: nothing
        friday: get money
        saturday: get bitches
        sunday: nothing
        monday: nothing
        tuesday: nothing


    auto now = std::chrono::system_clock::now();
    auto seconds = std::chrono::time_point_cast<std::chrono::seconds>(now);
    auto fractional_seconds = now - seconds;
    std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
