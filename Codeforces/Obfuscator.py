import re
import random
import string
from clang.cindex import Index, CursorKind, Config, Cursor
Config.set_library_file(r'E:\Env\LLVM\bin\libclang.dll')

unsed_names = set()
for i in range(26):
    for j in range(26):
        unsed_names.add(string.ascii_lowercase[i] + string.ascii_lowercase[j])

def generate_random_name():
    return unsed_names.pop()

def extract_identifiers(filename):
    index = Index.create()
    translation_unit = index.parse(filename)
    identifiers = set()

    def visit_node(node: Cursor):
        if node.kind in {CursorKind.VAR_DECL, CursorKind.FUNCTION_DECL, CursorKind.PARM_DECL}:
            if node.spelling != 'main':
                identifiers.add(node.spelling)
        for child in node.get_children():
            visit_node(child)

    visit_node(translation_unit.cursor)
    return identifiers

def obfuscate_code(code, obfuscation_map):
    for original, obfuscated in obfuscation_map.items():
        code = re.sub(r'\b' + re.escape(original) + r'\b', obfuscated, code)
    return code

def remove_comments(code):
    code = re.sub(r'//.*', '', code)
    code = re.sub(r'/\*.*?\*/', '', code, flags=re.DOTALL)
    return code

def remove_extra_spaces(code):
    def replacer(match):
        return match.group(0).replace(' ', '\x00')

    code = re.sub(r'".*?"', replacer, code)
    lines = code.split('\n')
    new_lines = []
    for line in lines:
        if not line.strip().startswith('#'):
            line = re.sub(r'\s+', ' ', line)
        new_lines.append(line)
    code = '\n'.join(new_lines)
    code = re.sub(r'\x00', ' ', code)
    return code

if __name__ == "__main__":
    input_filename = 'C_MEX_Cycle.cpp'
    output_filename = 'obfuscated_out.cpp'
    with open(input_filename, 'r', encoding='utf-8') as file:
        code = file.read()

    code = remove_comments(code)
    code = remove_extra_spaces(code)

    identifiers = extract_identifiers(input_filename)
    obfuscation_map = {identifier: generate_random_name() for identifier in identifiers}
    obfuscated_code = obfuscate_code(code, obfuscation_map)

    with open(output_filename, 'w', encoding='utf-8') as file:
        file.write(obfuscated_code)