package com.springboot.SocialMediaApi.users;

import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.function.Predicate;

@Service
public class UserDaoService {
    private static List<User> users = new ArrayList<>();
    private static int userCount = 0;

    static {
        users.add(new User(++userCount, "Sid", LocalDate.now().minusYears(22)));
        users.add(new User(++userCount, "Sejal", LocalDate.now().minusYears(20)));
        users.add(new User(++userCount, "Abha", LocalDate.now().minusYears(15)));
    }

    public List<User> findAll() {
        return users;
    }

    public User findOne(int id) {
        Predicate<? super User> predicate
                = user -> user.getId().equals(id);
        return users.stream().filter(predicate).findFirst().orElse(null);
    }

    public User save(User user) {
        user.setId(++userCount);
        users.add(user);
        return user;
    }

    public void deleteById(int id) {
        Predicate<? super User> predicate
                = user -> user.getId().equals(id);
        users.removeIf(predicate);
    }

}
