#!/usr/bin/python3

from PyQt5.QtCore import QDate, QTime, QDateTime, Qt

now = QDate.currentDate()

print(now.toString(Qt.ISODate))
print(now.toString(Qt.DefaultLocaleLongDate))

datetime = QDateTime.currentDateTime()

print(datetime.toString())

time = QTime.currentTime()

print(time.toString(Qt.DefaultLocaleLongDate))

now2 = QDateTime.currentDateTime()

print("Local datetime: ", now2.toString(Qt.ISODate))
print("Universal datetime: ", now2.toUTC().toString(Qt.ISODate))

print("The offset from UTC is: {0} seconds".format(now2.offsetFromUtc()))


