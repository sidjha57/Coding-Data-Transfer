import { useState, useEffect } from "react";



const useFetch = (url) => {
  // outputting lists
  const [data, setData] = useState(null);
  const [isPending, setIsPending] = useState(true);
  const [error, setError] = useState(null);

  /* useEffect runs everytime when rendering happens we can pass dependencies which will specify when 
    when should the statement be run after rendering if the dependency is empty array it will run only 
    once. It is generally used to fetch data */
  useEffect(() => {
    const abortCont = new AbortController();

    fetch(url, {signal: abortCont.signal})
      .then((res) => {
        if (!res.ok) {
          throw Error(`could not fetch the data for that resource`);
        }
        return res.json();
      })
      .then((data) => {
        setData(data);
        setIsPending(false);
        setError(null);
      })
      .catch((err) => {
        if (err.name === 'AbortError') {
            console.log('fetch aborted');
        } else {
            setIsPending(false);
            setError(err.message);
        }
      });

      /* we are doing this because when we change our page from home the fetch 
      request is still running in the background but it can't pupulate the data 
      because the blog list component does not exists*/
      return () => abortCont.abort(); 
  }, [url]);

  return { data, isPending, error };
}

export default useFetch;