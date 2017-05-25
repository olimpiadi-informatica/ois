with open("input.txt", "r") as f:
  data = f.read()

data = data[data.index("\n") + 1:]

while "&amp;" in data:
  data = data.replace("&amp;", "&")

with open("output.txt", "w") as f:
  f.write(str(len(data)) + "\n" + data)
