def alarm_clock(day, vacation):
  weekday = "7:00" if not vacation else "10:00"
  weekend = "10:00" if not vacation else "off"
  return weekday if day not in [6,0] else weekend
