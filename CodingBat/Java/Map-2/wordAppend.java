public String wordAppend(String[] strings) {
  String out = "";
  Map<String, Integer> map = new HashMap();
  for (String s:strings) {
    if (map.containsKey(s)) {
      int val = map.get(s) + 1;
      if (val % 2 == 0) 
        out = out + s;
      map.put(s, val);
    } else 
      map.put(s, 1);
  }
  return out;
}
