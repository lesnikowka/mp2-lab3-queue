#include "tqueue.h"
#include <gtest.h>

TEST(TQueue, can_create_queue) {
	ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, can_push_element_and_pop_it) {
	TQueue<int> q;
	bool flag = true;

	for (int i = 0; i < 20; i++)
		q.push(i);

	for (int i = 0; i < 20; i++)
		if (q.pop() != i) flag = false;

	EXPECT_TRUE(flag);
}

TEST(TQueue, empty_correct_if_queue_is_empty) {
	TQueue<int> q;

	EXPECT_TRUE(q.empty());
}

TEST(TStack, empty_correct_if_queue_is_not_empty) {
	TQueue<int> q;

	q.push(1);

	EXPECT_FALSE(q.empty());
}

TEST(TStack, count_is_correct) {
	TQueue<int> q;

	q.push(1); q.push(2);

	EXPECT_EQ(2, q.count());
}

TEST(TStack, throw_after_pop_if_queue_is_empty) {
	TQueue<int> q;

	ASSERT_ANY_THROW(q.pop());
}

TEST(TStack, can_copy_queue) {
	bool equality = true;
	TQueue<int> q1;
	for (int i = 0; i < 20; i++)
		q1.push(i);

	TQueue<int> q2(q1);

	if (q1.count() != q2.count()) equality = false;
	while (!q1.empty())
		if (q1.pop() != q2.pop()) equality = false;

	EXPECT_TRUE(equality);
}


