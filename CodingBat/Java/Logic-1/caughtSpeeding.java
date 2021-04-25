public int caughtSpeeding(int speed, boolean isBirthday) {
  if (!isBirthday) {
    if (speed <= 60) 
      return 0;
    else if (speed >= 61 && speed <= 80) 
      return 1;
    else 
      return 2;
  } else {
    if (speed <= 55) 
      return 0;
    else if (speed >= 66 && speed <= 85) 
      return 1;
    else if (speed >= 86) 
      return 2;
  }
  return 0;
}
