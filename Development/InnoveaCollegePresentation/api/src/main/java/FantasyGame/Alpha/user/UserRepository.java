package FantasyGame.Alpha.user;

import org.springframework.data.jpa.repository.JpaRepository;

public interface UserRepository extends JpaRepository<User, Long> {
    User findByPhonenum(String phone_no);
}
