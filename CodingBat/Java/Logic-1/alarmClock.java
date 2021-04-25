public String alarmClock(int day, boolean vacation) {
  if (vacation) {
    return day == 0 || day == 6 ? "off" : "10:00";
  } else  {
    return day == 0 || day == 6 ? "10:00" : "7:00";
  }
}
