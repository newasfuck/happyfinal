#include "PluginProcessor.h"

// JUCE 래퍼(AU/VST3)가 링크 타임에 찾는 '필수' 팩토리 심볼.
// 반드시 raw pointer 반환, 정확한 시그니처/이름 필요.
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new HappyAccidentAudioProcessor();
}
