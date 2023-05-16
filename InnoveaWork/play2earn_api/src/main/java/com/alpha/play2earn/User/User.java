package com.alpha.play2earn.User;

import jakarta.persistence.*;

import javax.xml.crypto.Data;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Date;

@Entity
@Table(name = "User")
public class User {
    @Id
    @GeneratedValue
    private Long id;

    // This needs to be worked on creating Account Id as First letter of first and last name and a random number
    @Column(name = "_accountID", nullable = false)
    private String accountId;

    @Column(name = "_userName", nullable = false)
    private String userName;

    @Column (name = "_phoneNumber")
    private String phoneNumber;

    @Column (name = "_emailID")
    private String emailID;

    @Column (name = "_dateOfBirth", nullable = false)
    private LocalDate dateOfBirth;

    @Column (name = "_residentLocation")
    private String residentLocation;

    @Column (name = "_accountCreatedDate")
//    private String date = LocalDateTime.now().format(DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss"));
    private LocalDateTime date = LocalDateTime.now();

    @Column (name = "_accountCreateLocation")
    private String createLocation;

    @Column (name = "_isAgeAllowed")
    private boolean isAgeAllowed;

    @Column (name = "_isLocationAllowed")
    private boolean isLocationAllowed;

    @Column (name = "_isKycComplete")
    private boolean isKycComplete = false;



    public User() {
    }
}
