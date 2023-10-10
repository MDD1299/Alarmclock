import datetime
from playsound import playsound

alarmHour = int(input("Enter Hour: "))
alarmMin = int(input("Enter Minutes: "))
alarmAm = input("am / pm: ")

if alarmAm == "pm":
    alarmHour += 12

while True:
    if (
        alarmHour == datetime.datetime.now().hour
        and alarmMin == datetime.datetime.now().minute
    ):
        print("Alarm is going off..")
        playsound("F:/flaskapp/Alarmclock/alarm.mp3")

        # Ask the user if they want to stop the alarm
        stop_alarm = input("Do you want to stop the alarm? (yes/no): ").lower()
        
        if stop_alarm == "yes":
            break
        else:
            # Continue playing the alarm until the user decides to stop it
            continue


