#include <iostream>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

int main() {
    int alarmHour, alarmMin;
    std::string alarmAm;

    std::cout << "Enter Hour: ";
    std::cin >> alarmHour;

    std::cout << "Enter Minutes: ";
    std::cin >> alarmMin;

    std::cout << "am / pm: ";
    std::cin >> alarmAm;

    if (alarmAm == "pm") {
        alarmHour += 12;
    }

    while (true) {
        time_t now = time(0);
        tm* localTime = localtime(&now);

        if (alarmHour == localTime->tm_hour && alarmMin == localTime->tm_min) {
            std::cout << "Alarm is going off.." << std::endl;
            PlaySound(TEXT("F:/flaskapp/Alarmclock/alarm.wav"), NULL, SND_FILENAME);

            std::string stopAlarm;
            std::cout << "Do you want to stop the alarm? (yes/no): ";
            std::cin >> stopAlarm;

            if (stopAlarm == "yes") {
                break;
            } else {
                continue;
            }
        }
    }

    return 0;
}

