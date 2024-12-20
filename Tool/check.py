import subprocess, time

def run_and_compare(i, input_file, output_file, exe_file):
    # 读取输入文件内容
    with open(input_file, 'r') as infile:
        input_data = infile.read()

    # 调用C++的exe程序
    process = subprocess.Popen(exe_file, stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    
    # 记录开始时间
    start_time = time.perf_counter()
    stdout, stderr = process.communicate(input=input_data.encode())
    # 记录结束时间
    end_time = time.perf_counter()
    # 计算执行时间
    execution_time = (end_time - start_time) * 1000
    
    # 读取输出文件内容
    with open(output_file, 'r') as outfile:
        expected_output = outfile.read()

    # 比较exe程序的输出和期望的输出
    if stdout.decode().strip() == expected_output.strip():
        print(f"\033[36m数据点{i} - 输出匹配 - {execution_time:.2f}ms\033[m")
    else:
        print(f"\033[33m数据点{i} - 输出不匹配 - {execution_time:.2f}ms\033[m")
        print("期望输出:")
        print(expected_output.strip())
        print("实际输出:")
        print(stdout.decode().strip())

for i in range(1, 20):
    # 示例调用
    run_and_compare(i, fr'C:\Users\21988\Downloads\data\{i}.in', fr'C:\Users\21988\Downloads\data\{i}.out', r"C:\Users\21988\Downloads\data\output\test.exe")