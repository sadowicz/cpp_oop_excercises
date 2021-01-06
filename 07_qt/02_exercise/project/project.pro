TEMPLATE = subdirs

SUBDIRS += \
    cli \
    gui \
    tests \
    utils

utils.subdir = utils
cli.subdirs = cli
gui.subdirs = gui
tests.subdir = tests

cli.depends = utils
gui.depends = utils
tests.depends = utils
