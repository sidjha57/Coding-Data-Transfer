import org.junit.jupiter.api.*;

public class MyBeforeAfterTest {

    @BeforeAll
    static void beforeAll() {
        System.out.println("beforeAll");
    }
    @BeforeEach
    void beforeEach() {
        System.out.println("BeforeEach");
    }

    // There is no garantee that the execution would take sequentially
    @Test
    void test1() {
        System.out.println("test 1");
    }
    @Test
    void test2() {
        System.out.println("test 2");
    }
    @Test
    void test3() {
        System.out.println("test 3");
    }

    @AfterEach
    void afterEach() {
        System.out.println("afterEach");
    }

    @AfterAll
    static void afterAll() {
        System.out.println("afterAll");
    }
}
