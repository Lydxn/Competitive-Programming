public Map<String, String> pairs(String[] strings) {
  Map<String, String> map = new HashMap();
  for (String i : strings) {
    map.put(i.substring(0, 1), i.substring(i.length() - 1));
  }
  return map;
}
