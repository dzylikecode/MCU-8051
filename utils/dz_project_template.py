import os
import shutil
import sys

exp_path = "../experiment"
docs_path = "../docs/experiment"
assets_makefile = "assets/Makefile"
assets_main = "assets/main.c"
assets_readme = "assets/README.md"
summary_file = "../docs/experiment/summary.md"
link_format = "experiment/%s/README.md"


def create_folder(project_name):
    exp_folder = os.path.join(exp_path, project_name)
    docs_folder = os.path.join(docs_path, project_name)
    if os.path.exists(exp_folder) or os.path.exists(docs_folder):
        raise FileExistsError("Folder already exists")
    os.makedirs(exp_folder)
    print("Created folder: {}".format(exp_folder))
    os.makedirs(docs_folder)
    print("Created folder: {}".format(docs_folder))
    return exp_folder, docs_folder


def create_exp_file(exp_folder):
    shutil.copy(assets_makefile, exp_folder)
    print("Created file: {}".format(os.path.join(exp_folder, "Makefile")))
    shutil.copy(assets_main, exp_folder)
    print("Created file: {}".format(os.path.join(exp_folder, "main.c")))


def create_docs_file(docs_folder):
    shutil.copy(assets_readme, docs_folder)
    print("Created file: {}".format(os.path.join(docs_folder, "README.md")))


def modify_summary(project_name):
    with open(summary_file, "a") as f:
        link = link_format % project_name
        f.write("- [ ](%s)\n" % (link))


if __name__ == "__main__":
    # 1.
    # create_folder("hello-dz")
    # 2.
    # exp_folder, docs_folder = create_folder("hello-dz")
    # create_exp_file(exp_folder)
    # 3.
    # exp_folder, docs_folder = create_folder("hello-dz")
    # create_exp_file(exp_folder)
    # create_docs_file(docs_folder)
    # 4.
    # if len(sys.argv) != 2:
    #     print("Usage: python3 dzmkdir.py <project_name>")
    #     sys.exit(1)
    # project_name = sys.argv[1]
    # exp_folder, docs_folder = create_folder(project_name)
    # create_exp_file(exp_folder)
    # create_docs_file(docs_folder)
    # 5.
    if len(sys.argv) != 2:
        print("Usage: python3 dzmkdir.py <project_name>")
        sys.exit(1)
    project_name = sys.argv[1]
    exp_folder, docs_folder = create_folder(project_name)
    create_exp_file(exp_folder)
    create_docs_file(docs_folder)
    modify_summary(project_name)
    pass
