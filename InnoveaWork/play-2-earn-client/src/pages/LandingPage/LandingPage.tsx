import React, { useState } from "react";
import Logo from "../../assets/LandingPage/Logo.png";
import BackgroundImage from "../../assets/LandingPage/Hero-background.jpg";
import HeroRight from "../../assets/LandingPage/Hero-right.png";
import VerifiedIcon from "../../assets/LandingPage/Verified.png";
import UpiIcon from "../../assets/LandingPage/Upi.png";
import RewardsIcon from "../../assets/LandingPage/Reward.png";
import DownloadIcon from "../../assets/LandingPage/Download.png";
import IphoneBanner from "../../assets/LandingPage/Iphone-banner.jpg";
import LearnMockup from "../../assets/LandingPage/Learn-mockup.jpg";
import Avatar from "../../assets/LandingPage/avatar.webp";
import RewardsMockup from "../../assets/LandingPage/Rewards-mockup.png";
import KycIcon from "../../assets/LandingPage/kyc.svg";
import UserIcon from "../../assets/LandingPage/user.svg";
import WhatsappIcon from "../../assets/LandingPage/whatsapp.svg";
import FbIcon from "../../assets/LandingPage/fb.svg";
import InstagramIcon from "../../assets/LandingPage/instagram.svg";
import TwitterIcon from "../../assets/LandingPage/twitter.svg";
import QrCode from "../../assets/LandingPage/QrCode.png";
// import QRCode from "qrcode.react";


import "./LandingPage.css";
import { Navigate, useNavigate, useSearchParams } from "react-router-dom";
import { useAuth } from "../../context/AuthContext";
import { frontendUrl } from "../../js/urls";



const LandingPage = () => {

  const {setIsInstalled} = useAuth()
  const [modalOpen, setModalOpen] = React.useState(false);
  const navigate = useNavigate()
  const [params] = useSearchParams();

  const [deferredPrompt, setDeferredPrompt] = React.useState<any>(null);

  React.useEffect(() => {
    function handleBeforeInstallPrompt(event: any) {
      event.preventDefault();
      setDeferredPrompt(event);
    }

    window.addEventListener('beforeinstallprompt', handleBeforeInstallPrompt);

    return () => {
      window.removeEventListener('beforeinstallprompt', handleBeforeInstallPrompt);
    };

    
  }, []);

  React.useEffect(() => {
    function handleAppInstalled(event: Event) {
      console.log('PWA installed!');
      // Automatically open the PWA once it has been installed
      setTimeout(() => {
        window.location.href = frontendUrl;
      }, 9000);
    }

    window.addEventListener('appinstalled', handleAppInstalled);

    return () => {
      window.removeEventListener('appinstalled', handleAppInstalled);
    };
  }, []);

  function handleInstallButtonClick() {
    if (deferredPrompt) {
      deferredPrompt.prompt();
      deferredPrompt.userChoice.then((choiceResult: any) => {
        if (choiceResult.outcome === 'accepted') {
          console.log('User accepted the install prompt');
        } else {
          console.log('User dismissed the install prompt');
        }
        setDeferredPrompt(null);
      });
    }
  }



  // if() {
  //   handleInstallButtonClick()
  // }

  // let deferredPrompt : any;
  // window.addEventListener('beforeinstallprompt', (e : any) => {
  //     deferredPrompt = e;
  //     console.log(`'beforeinstallprompt' event was fired.`, e);
  // });

  // window.addEventListener('appinstalled', () => {
  //     deferredPrompt = null;
  //     console.log('PWA was installed');
  // });

  // const handleClick = async () => {
  //   try {

  //     deferredPrompt.prompt();
  //     const { outcome } = await deferredPrompt.userChoice;
  //     console.log(outcome);
  //     if (outcome === 'accepted') {
  //       deferredPrompt = null;
  //       // setIsInstalled(true);
  //       console.log("Moved to login page")
  //       return <Navigate to={"/"} />
  //       // location.reload()
  //     }
  //   } catch(err) {
  //     console.log(err)
  //     alert("Already Installed, Open the Installed Version")
  //   }
  // }

  function isMobileDevice(): boolean {
    const userAgent = navigator.userAgent.toLowerCase();
    return /android|webos|iphone|ipod|blackberry|windows phone|iemobile|opera mini/i.test(userAgent);
  }

  const handlingLandingPageFlow = () => {
    if (isMobileDevice()) {
      handleInstallButtonClick();
    } else {
      setModalOpen(true);
    }
  }


  console.log(isMobileDevice()); 


  return (
    <div className="landing-page">
      <div
        className="hero-section"
        style={{
          backgroundImage: `url(${BackgroundImage})`,
        }}
      >
        <div className="logo">
          <img alt="" className="w-44" src={Logo} />
        </div>

        <div className="hero-content mt-14">
          <div className="hero-left">
            <div className="text-white text-5xl hero-content-1">
              Take the smarter option to uplevel your trading game !
            </div>
            <div className="text-white text-md my-10 hero-content-2">
              Learn everyday, test your decision making in a safe space and get
              into a habit of making reasonable returns more consistently !
            </div>
            <button
              className="download-button text-xl"
              // onClick={() => handleClick()}
              onClick={() => handlingLandingPageFlow()}
            >
              Download App now !
            </button>
          </div>
          <img alt="" className="hero-image" src={HeroRight} />
        </div>
      </div>
      {modalOpen && (
        <div className="fixed inset-0 flex items-center justify-center bg-black bg-opacity-50" onClick={() => {
                setModalOpen(false);
              }}>
          <div className="bg-white rounded-md pt-3 pb-5">
            <div
              className="flex justify-end text-md px-5 font-bold mb-3 cursor-pointer"
              onClick={() => {
                setModalOpen(false);
              }}
            >
              ✕
            </div>
            <div className="flex flex-row items-center px-10">
              <div className="mr-10 align-middle">
                <div className="font-semibold ">
                  Download MarketPlay on your phone
                </div>
                <div>1. Scan the QR Code on your phone.</div>
                <div>2. Download the app to Win and Earn big.</div>
              </div>
              {/* <QRCode value={frontendUrl} className="w-36" /> */}
              <img src={QrCode} alt="" className="w-36"/>
            </div>
          </div>
        </div>
      )}

      <div className="features-list">
        <div className="set">
          <div className="features">
            <div>
              <img alt="" src={VerifiedIcon} />
            </div>
            <div className="feature-tagline">100% Safe and Legal</div>
          </div>
          <div className="features">
            <div>
              <img alt="" src={UpiIcon} />
            </div>
            <div className="feature-tagline">Safe Withdrawals</div>
          </div>
        </div>
        <div className="set">
          <div className="features">
            <div>
              <img alt="" src={RewardsIcon} />
            </div>
            <div className="feature-tagline">$5Cr + Rewards till date</div>
          </div>
          <div className="features">
            <div>
              <img alt="" src={DownloadIcon} />
            </div>
            <div className="feature-tagline">1mn+ Downloads</div>
          </div>
        </div>
      </div>
      <div className="iphone-banner flex justify-center py-10 px-5">
        <img alt="" src={IphoneBanner} />
      </div>
      <div className="learn-module">
        <div className="learn-feature-list">
          <div className="learn-heading for-desktop">Learn with us</div>
          <div>
            <div className="learn-feature">
              <img alt="" src={KycIcon} />
              <div className="learn-content">
                <div className="feature-heading">
                  Daily bite sized technical concepts
                </div>
                <div className="feature-description">
                  Technical concepts simplified and shared as they happen in the
                  market
                </div>
              </div>
            </div>

            <div className="learn-feature">
              <img alt="" src={UserIcon} />
              <div className="learn-content">
                <div className="feature-heading">
                  Mindset principles to navigate volatility
                </div>
                <div className="feature-description">
                  Frank conversations with traders and best practices from
                  experts
                </div>
              </div>
            </div>

            <div className="learn-feature">
              <img alt="" src={KycIcon} />
              <div className="learn-content">
                <div className="feature-heading">Regular market updates</div>
                <div className="feature-description">
                  Key price action and news to prepare you for tomorrow
                </div>
              </div>
            </div>

            <button className="start-learning">Start Learning</button>
          </div>
        </div>
        <img alt="" className="mockup-image" src={LearnMockup} />
        <div className="learn-heading for-mobile">Learn with us</div>
      </div>

      <div className="learn-module mt-24">
        <div className="learn-feature-list">
          <div className="learn-heading for-desktop">Earn rewards with us</div>
          <div>
            <div className="learn-feature">
              <img alt="" src={KycIcon} />
              <div className="learn-content">
                <div className="feature-heading">
                  Test your market views in a safe space
                </div>
                <div className="feature-description">
                  Create portfolios and compete against other traders with
                  smaller amounts at risk
                </div>
              </div>
            </div>

            <div className="learn-feature">
              <img alt="" src={UserIcon} />
              <div className="learn-content">
                <div className="feature-heading">
                  Reasonable returns in a consistent way
                </div>
                <div className="feature-description">
                  More repeatable payouts than option buying or other fantasy
                  games
                </div>
              </div>
            </div>

            <div className="learn-feature">
              <img alt="" src={KycIcon} />
              <div className="learn-content">
                <div className="feature-heading">
                  Withdraw rewards or use to upskill
                </div>
                <div className="feature-description">
                  Withdraw directly to your back account or use to upskill with
                  custom courses
                </div>
              </div>
            </div>

            <button className="start-learning">Start Earning Rewards</button>
          </div>
        </div>
        <img alt="" className="mockup-image" src={RewardsMockup} />
        <div className="learn-heading for-mobile">Earn rewards with us</div>
      </div>

      <div className="testimonials">
        <div className="testimonials-heading">Testimonials</div>
        <div className="testimonials-list">
          <div className="testimonial-card">
            <img alt="" src={Avatar} />
            <div className="testimonial-body">
              <div className="testimonial-name">Jay P.</div>
              <div className="testimonial-content">
                Add paragraph text. Click “Edit Text” to customize this theme
                across your site. You can update and reuse text themes.
              </div>
            </div>
          </div>

          <div className="testimonial-card">
            <img alt="" src={Avatar} />
            <div className="testimonial-body">
              <div className="testimonial-name">Shubhomoy B.</div>
              <div className="testimonial-content">
                Add paragraph text. Click “Edit Text” to customize this theme
                across your site. You can update and reuse text themes.
              </div>
            </div>
          </div>

          <div className="testimonial-card">
            <img alt="" src={Avatar} />
            <div className="testimonial-body">
              <div className="testimonial-name">Jiten P.</div>
              <div className="testimonial-content">
                Add paragraph text. Click “Edit Text” to customize this theme
                across your site. You can update and reuse text themes.
              </div>
            </div>
          </div>

          <div className="testimonial-card">
            <img alt="" src={Avatar} />
            <div className="testimonial-body">
              <div className="testimonial-name">Jay P.</div>
              <div className="testimonial-content">
                Add paragraph text. Click “Edit Text” to customize this theme
                across your site. You can update and reuse text themes.
              </div>
            </div>
          </div>

          <div className="testimonial-card">
            <img alt="" src={Avatar} />
            <div className="testimonial-body">
              <div className="testimonial-name">Jay P.</div>
              <div className="testimonial-content">
                Add paragraph text. Click “Edit Text” to customize this theme
                across your site. You can update and reuse text themes.
              </div>
            </div>
          </div>
        </div>{" "}
      </div>

      <div className="footer">
        <img alt="" src={Logo} className="footer-logo" />
        <div className="footer-tabs">
          <div className="footer-tab">Privacy</div>
          <div className="footer-tab">T&C</div>
          <div className="footer-tab">Contact Us</div>
          <div className="footer-tab">FAQs</div>
        </div>
        <div className="social-media">
          <img alt="" src={InstagramIcon} />
          <img alt="" src={FbIcon} />
          <img alt="" src={WhatsappIcon} />
          <img alt="" src={TwitterIcon} />
        </div>
        <div className="text-white mt-2 footer-text">© 2022 www.marketplay.com</div>
        <div className="text-white footer-text">All rights reserved.</div>
        <div></div>
      </div>
    </div>
  );
};

export default LandingPage;
