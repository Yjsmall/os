import os


def execute_make_clean(folder):
    makefile_path = os.path.join(folder, "Makefile")
    if os.path.exists(makefile_path):
        with open(makefile_path, "r") as f:
            makefile_content = f.read()
            if "clean:" in makefile_content:
                os.system("cd {} && make clean".format(folder))


def visit_folders(directory):
    for item in os.listdir(directory):
        item_path = os.path.join(directory, item)
        if os.path.isdir(item_path):
            execute_make_clean(item_path)
            visit_folders(item_path)


def main():
    current_dir = os.getcwd()
    visit_folders(current_dir)


if __name__ == "__main__":
    main()
