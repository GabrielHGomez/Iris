#include "../src/common.hpp"

#include <gtest/gtest.h>
#include "test_structs.hpp"

TEST(SharedMemoryTest, WriteAndReadPosition) {
    SharedMemory<Position> writer("test_pos", true);
    writer->x = 10;
    writer->y = 20;

    SharedMemory<Position> reader("test_pos", false);
    EXPECT_EQ(reader->x, 10);
    EXPECT_EQ(reader->y, 20);
}

TEST(SharedMemoryTest, WriteAndReadPerson) {
    SharedMemory<Person> writer("test_person", true);
    std::snprintf(writer->name, sizeof(writer->name), "%s", "Alice");
    writer->age = 25;
    writer->height = {5, 7};
    writer->weight = 130.5f;

    SharedMemory<Person> reader("test_person", false);
    EXPECT_STREQ(reader->name, "Alice");
    EXPECT_EQ(reader->age, 25);
    EXPECT_EQ(reader->height[0], 5);
    EXPECT_EQ(reader->height[1], 7);
    EXPECT_FLOAT_EQ(reader->weight, 130.5f);
}

TEST(SharedMemoryTest, ReaderSeesWriterUpdates) {
    SharedMemory<Position> writer("test_update", true);
    SharedMemory<Position> reader("test_update", false);

    writer->x = 1;
    EXPECT_EQ(reader->x, 1);

    writer->x = 100;
    EXPECT_EQ(reader->x, 100);
}

TEST(SharedMemoryTest, OpenNonExistentThrows) {
    EXPECT_ANY_THROW(SharedMemory<Position>("not_a_real_segment", false));
}
