#
# Register all tests for the current module
#
# DCMTK_ADD_TESTS - macro which registers all tests
# MODULE - name of the module that we are called for
#

MACRO(DCMTK_ADD_TESTS MODULE)
    file(STRINGS tests.cc AVAIL_TESTS REGEX OFTEST_REGISTER)
    FOREACH(TEST_LINE ${AVAIL_TESTS})
        # TODO: How can we parse tests.cc in a saner way?
        STRING(REPLACE "OFTEST_REGISTER(" "" TEST ${TEST_LINE})
        STRING(REPLACE ")" "" TEST ${TEST})
        # This assumes that test names are globally unique
        ADD_TEST("${TEST}" "${MODULE}_tests" "${TEST}")
    ENDFOREACH(TEST_LINE)
ENDMACRO(DCMTK_ADD_TESTS)