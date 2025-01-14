N = io.read("n")
local n = 1
local rest = N
local cnt = 0
while (n <= N) do
  local l = 0
  local tn = n
  while tn > 0 do
      l = l + 1
      tn = tn // 10
  end
  if l % 2 == 1 then
    cnt = cnt + math.min(9 * n, rest)
  end
  rest = math.max(0, rest - 9 * n)
  n = 10 * n
end
print(cnt)