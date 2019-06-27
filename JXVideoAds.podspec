

Pod::Spec.new do |s|
  s.name             = 'JXVideoAds'
  s.version          = '0.1.0'
  s.summary          = 'JXVideoAds offers video advertising'


  s.description      = 'JXVideoAds supports playback progress acquisition, volume control, playback control and so on'

  s.homepage         = 'https://github.com/Code-TanJX/googleads-ima-JXAVideoAds'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'Code-TanJX' => 'Code_TanJX@163.com' }
  s.source           = { :git => 'https://github.com/Code-TanJX/googleads-ima-JXAVideoAds.git', :tag => s.version.to_s }

  s.ios.deployment_target = '8.0'
  
  if ENV['IS_FRAMEWORK']
      
      s.source_files = 'JXVideoAds/Classes/**/*.h'
      s.vendored_frameworks = 'JXVideoAds/Library/JXVideoAds.framework'
      s.dependency 'GoogleAds-IMA-iOS-SDK'
      
  else
  
      s.subspec 'API' do |api|
          api.source_files = 'JXVideoAds/Classes/API/**/*'
          api.public_header_files = 'JXVideoAds/Classes/API/**/*.h'
          api.dependency 'JXVideoAds/Common'
          api.dependency 'JXVideoAds/GoogleIma'
      end
      
      s.subspec 'Common' do |common|
          common.source_files = 'JXVideoAds/Classes/Common/**/*'
          common.public_header_files = 'JXVideoAds/Classes/Common/**/*.h'
          common.dependency 'JXVideoAds/GoogleIma'
      end
      
      s.subspec 'GoogleIma' do |googleIma|
          googleIma.source_files = 'JXVideoAds/Classes/GoogleIma/**/*'
          googleIma.public_header_files = 'JXVideoAds/Classes/GoogleIma/**/*.h'
          googleIma.dependency 'GoogleAds-IMA-iOS-SDK'
      end

  end
  

end
