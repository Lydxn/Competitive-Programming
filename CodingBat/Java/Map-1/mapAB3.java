public Map<String, String> mapAB3(Map<String, String> map) {
  if (map.containsKey("a") ^ map.containsKey("b")) {
    if (map.containsKey("a"))
      map.put("b", map.get("a"));
    else
      map.put("a", map.get("b"));
  }
  return map;
}
