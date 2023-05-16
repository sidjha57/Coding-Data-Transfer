<html>
    <head>
        <title>Login PAGE</title>
    </head>

    <body>
        <div class="container">
            <h1>Welcome to login page! </h1>
            <form method="post">
                Name: <input type="text" name="name">
                Password: <input type="password" name="password">
                <input type="submit">
            </form>
            <h4>${errorMessage}</h4>
        </div>
    </body>

</html>