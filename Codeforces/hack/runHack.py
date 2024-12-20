import subprocess
import time

def run_hack_and_cpp(hack_script, cpp_executable):
    # 调用 hack.py 生成测试数据
    start_time = time.time()
    #hack_process = subprocess.Popen(['python', hack_script], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    hack_process = subprocess.Popen(['python', hack_script], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    hack_output, hack_error = hack_process.communicate()
    hack_time = time.time() - start_time

    if hack_process.returncode != 0:
        print(f"Error running {hack_script}: {hack_error.decode()}")
        return

    # 调用 C++ 可执行文件并传递测试数据
    start_time = time.time()
    cpp_process = subprocess.Popen([cpp_executable], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    cpp_output, cpp_error = cpp_process.communicate(input=hack_output)
    cpp_time = time.time() - start_time

    if cpp_process.returncode != 0:
        print(f"Error running {cpp_executable}: {cpp_error.decode()}")
        return

    # 输出 C++ 可执行文件的结果
    print(cpp_output.decode())

    # 输出执行耗时
    print(f"hack.py execution time: {hack_time:.4f} seconds")
    print(f"{cpp_executable} execution time: {cpp_time:.4f} seconds")

if __name__ == "__main__":
    hack_script = './hacker-v2.py'  # hack.py 脚本路径
    cpp_executable = './output/_tohack.exe'  # C++ 可执行文件路径
    #cpp_executable = '../output/F_Easy_Demon_Problem.exe'  # C++ 可执行文件路径

    run_hack_and_cpp(hack_script, cpp_executable)