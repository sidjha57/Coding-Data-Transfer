module.exports = {
  content: ["./src/**/*.{js,jsx,ts,tsx}"],
  theme: {
    extend: {
      fontFamily: {
        manrope: ['Manrope', 'sans-serif'],
        satoshi:  ['Satoshi-Variable', 'ui-sans-serif', 'system-ui'],
      },
      colors: {
        "primary-color": "var(--primary-color)",
        "dark-background": "var(--dark-background)",
        "light-background": "var(--light-background)",
        "background": "var(--background)",
        "dark-text": "var(--dark-text)",
        "light-text": "var(--light-text)",
      }
    },
  },
  plugins: [],
}