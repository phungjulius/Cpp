

class UniqueRng {
public:
    UniqueRng(unsigned int min, unsigned int max);
    int operator()();
private:
    // add something here...
};


void test_generator(UniqueRng ur, int count);


int main(void) {
    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}

