const Home = () => {

    const handleClick = (e) => {
        console.log('hello, Siddhartians',e) // a event object is directly passed inside handleClick
    }

    // const handleClickAgain = (name,e) => {
    //     console.log(`hello ${name}`,e.target) // target gives us the access to what is written in tags
    // }
    

    return ( 
        <div className="home">
            <h2>Home Page</h2>
            {/* we cannot pass a argument in handleClick as it will execute it directly */}
            <button onClick={handleClick}>Click me</button> 
            {/* we have wrapped the handleClickAgain inside an anonymous function
            <button onClick={(e) => {
                handleClickAgain('Sid',e);
            }}>Click Me Again</button>  */}
        </div>
     );
}
 
export default Home;