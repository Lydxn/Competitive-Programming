public int triangle(int rows) {
  return rows == 0 ? 0 : triangle(rows - 1) + rows;
}
